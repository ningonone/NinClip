#include "database.h"

#include <QListWidgetItem>

Database::Database(QObject *parent)
    : QObject{parent}
{}
Database::~Database()
{
    DB.close();
}

bool Database::dataBaseInit()
{
    DB = QSqlDatabase::addDatabase("QSQLITE");
    DB.setDatabaseName("ninclip.db");
    if(!DB.open())
    {
        qDebug() << "Filed to open database" << DB.lastError().text();
        return false;
    }
    QSqlQuery query;
    QString createTable = R"(
        CREATE TABLE IF NOT EXISTS Main (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            time TEXT NOT NULL,
            data_type TEXT NOT NULL,
            data BLOB NOT NULL
        )
    )";
    if(!query.exec(createTable))
    {
        qDebug() << "Failed to create table:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Database::dataBaseCreateTable(const QString &tableName)
{
    QSqlQuery query;
    QString createTable = R"(
        CREATE TABLE IF NOT EXISTS %1 (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            time TEXT NOT NULL,
            data_type TEXT NOT NULL,
            data BLOB NOT NULL
        )
    )";
    QString createTableSQL = createTable.arg(tableName);
    if(!query.exec(createTableSQL))
    {
        qDebug() << "Failed to create table:" << query.lastError().text();
        return false;
    }
    return true;
}


int Database::dataBaseInsertData(const QString &tableName, QString dataType, QListWidgetItem *item, QString time)
{
    // 准备 SQL 插入语句
    QSqlQuery query;
    QString sqlTemplate = QString("INSERT INTO %1 (time, data_type, data)\nVALUES (?, ?, ?)");
    QString sqlQuery = sqlTemplate.arg(tableName);
    query.prepare(sqlQuery);

    // 绑定当前时间
    query.addBindValue(time);
    // 绑定数据类型 (text 或 image)
    query.addBindValue(dataType);

    if (dataType == "text") {
        QString text = item->text();
        if (text.isEmpty()) {
            qDebug() << "Text is empty, cannot insert into database.";
            return -1;  // 提前返回，防止插入空数据
        }
        query.addBindValue(text.toUtf8());
    }
    else if (dataType == "image") {
        QImage image = item->data(Qt::UserRole).value<QImage>();
        if (image.isNull()) {
            qDebug() << "Item has no image, cannot insert into database.";
            return -1;  // 提前返回，防止插入空图片
        }

        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::WriteOnly);
        if (!image.save(&buffer, "PNG")) {
            qDebug() << "Failed to save pixmap to buffer.";
            return -1;  // 如果无法保存图像，提前返回
        }
        query.addBindValue(byteArray);
    }

    // 执行 SQL 语句
    if (!query.exec()) {
        qDebug() << "Failed to insert data:" << query.lastError().text();
        return -1;
    }
    qDebug() << "Data inserted successfully!";
    return query.lastInsertId().toInt();
}

void Database::dataBaseRemoveDB()
{
    // 关闭数据库连接
    QString dbFilePath = DB.databaseName(); // 获取数据库文件路径
    DB.close(); // 关闭数据库连接

    // 移除数据库文件
    if (QFile::remove(dbFilePath)) {
        qDebug() << "Database file deleted successfully!";
    } else {
        qDebug() << "Failed to delete database file!";
    }
    // 移除连接
    QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
}

void Database::dataBaseRemoveTableItem(const QString &tableName, int removeId)
{
    // 准备 SQL DELETE 语句
    QSqlQuery query;
    QString sqlQuery = QString("DELETE FROM %1 WHERE id = ?").arg(tableName);
    query.prepare(sqlQuery);

    // 绑定需要删除的行的 id
    query.addBindValue(removeId);

    // 执行查询
    if (!query.exec()) {
        qDebug() << "Failed to remove item from table" << tableName << "with id" << removeId << ":" << query.lastError().text();
        return;
    }

    // 检查是否成功删除
    if (query.numRowsAffected() > 0) {
        qDebug() << "Item with id" << removeId << "successfully removed from table" << tableName;
    } else {
        qDebug() << "No item found with id" << removeId << "in table" << tableName;
    }
}

QStringList Database::getAllTableNames() {
    QStringList tableNames;
    QSqlQuery query("SELECT name FROM sqlite_master WHERE type='table' AND name != 'sqlite_sequence';");
    if (query.exec()) {
        while (query.next()) {
            tableNames.append(query.value(0).toString());
        }
    } else {
        qDebug() << "Failed to fetch table names:" << query.lastError().text();
    }
    return tableNames;
}

QList<QListWidgetItem*> Database::getTableData(const QString &tableName) {
    QList<QListWidgetItem*> items;
    QSqlQuery query(QString("SELECT id, time, data_type, data FROM %1").arg(tableName));

    if (!query.exec()) {
        qDebug() << "Failed to fetch data from table:" << tableName << query.lastError().text();
        return items;
    }

    while (query.next()) {
        int id = query.value(0).toInt();
        QString time = query.value(1).toString();
        QString dataType = query.value(2).toString();
        QByteArray data = query.value(3).toByteArray();

        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(300, 50));

        if (dataType == "text") {
            QString text = QString::fromUtf8(data);
            item->setText(text);
            item->setToolTip(text + "\n\nTime: " + time);
            item->setData(Qt::UserRole+1, id);
        } else if (dataType == "image") {
            QImage image;
            image.loadFromData(data);
            if (!image.isNull()) {
                item->setIcon(QPixmap::fromImage(image));
                item->setData(Qt::UserRole, QVariant::fromValue(image));
                item->setData(Qt::UserRole+1, id);
                item->setSizeHint(QSize(300, 50));
            }
            item->setToolTip("Time: " + time);
        }

        items.append(item);
    }

    return items;
}

// 新增的搜索方法
QList<QListWidgetItem*> Database::getSearchData(const QString &searchText)
{
    QList<QListWidgetItem*> items;
    QSqlQuery query;
    query.prepare("SELECT data FROM Main WHERE data_type = 'text' AND data LIKE ?");

    // 使用 % 进行模糊查询
    QString queryString = "%" + searchText + "%";
    query.addBindValue(queryString);

    if (!query.exec()) {
        qDebug() << searchText;
        qDebug() << "Failed to search data:" << query.lastError().text();
        return items;
    }

    // 将查询结果存储为 QListWidgetItem 列表
    while (query.next()) {
        QString text = query.value(0).toString();
        QListWidgetItem *item = new QListWidgetItem(text);
        QString result = item->text();
        item->setSizeHint(QSize(300, 50));
        item->setToolTip(result);
        items.append(item);
    }

    return items;
}

bool Database::dataBaseRemoveTable(const QString &tableName)
{
    QSqlQuery query;
    QString sqlQuery = QString("DROP TABLE IF EXISTS %1").arg(tableName);

    if (!query.exec(sqlQuery)) {
        qDebug() << "Failed to remove table:" << query.lastError().text();
        return false;
    }

    qDebug() << "Table removed successfully:" << tableName;
    return true;
}
