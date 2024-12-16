#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>
#include <QListWidgetItem>

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = nullptr);
    ~Database();

public:
    bool dataBaseInit();
    bool dataBaseCreateTable(const QString &tableName);
    int  dataBaseInsertData(const QString &tableName, QString dataType, QListWidgetItem *item, QString time);
    void dataBaseRemoveDB();
    void dataBaseRemoveTableItem(const QString &tableName, int removeId);
    bool dataBaseRemoveTable(const QString &tableName);
    QStringList getAllTableNames();
    QList<QListWidgetItem*> getTableData(const QString &tableName);
    QList<QListWidgetItem*> getSearchData(const QString &searchText);

private:
    QSqlDatabase    DB;

};

#endif // DATABASE_H
