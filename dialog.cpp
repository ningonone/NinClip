#include "dialog.h"
#include "ui_dialog.h"
#include "ui_help.h"
#include <QDebug>
#include <QScreen>
#include <QInputDialog>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QHotkey>
#include <QFontDatabase>
#include <QMessageBox>
#include <QKeySequenceEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , ui_help(new Ui::Help)
{
    ui->setupUi(this);
    initDialog();
    initStyle();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::initDialog()
{
    // 初始化数据库
    m_db = new Database(this);
    m_db->dataBaseInit();
    on_actReloadDB_triggered();

    //初始化toolsButton
    QMenu *m_menu = new QMenu();
    m_menu->addAction(ui->actCreateGroup);
    m_menu->addAction(ui->actRemoveGroup);
    m_menu->addAction(ui->actShortCut);
    m_menu->addSeparator();
    m_menu->addAction(ui->actClearDB);
    m_menu->addAction(ui->actBackupDB);
    m_menu->addAction(ui->actReloadDB);
    m_menu->addSeparator();       // 添加分隔符
    m_menu->addAction(ui->actHelp);
    m_menu->addAction(ui->actExit);
    ui->toolButton->setMenu(m_menu);

    //初始化剪贴板
    m_clipboard = QApplication::clipboard();
    connect(m_clipboard, SIGNAL(dataChanged()), this, SLOT(do_clipboardDataChanged()));

    //初始化托盘图标
    m_trayIcon = new QSystemTrayIcon(QIcon(":/images/images/clip.ico"), this);
    connect(m_trayIcon, &QSystemTrayIcon::activated, this, &Dialog::do_trayIconActivated);

    //创建托盘菜单
    QMenu *trayMenu = new QMenu(this);
    trayMenu->addAction(ui->actClearDB);
    trayMenu->addAction(ui->actBackupDB);
    trayMenu->addAction(ui->actReloadDB);
    trayMenu->addSeparator();       // 添加分隔符
    trayMenu->addAction(ui->actExit);
    m_trayIcon->setContextMenu(trayMenu);
    m_trayIcon->show();

    //注册全局快捷键
    m_gobalRun = new QHotkey(QKeySequence("Ctrl+Alt+W"),true,this);
    connect(m_gobalRun, SIGNAL(activated()),this, SLOT(do_toggleWindow()));

    //初始化右击菜单
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(QPoint)),this, SLOT(do_showMainTableMenu()));

    //初始化事件过滤器
    ui->listWidget->installEventFilter(this);

    //按键聚焦搜索框
    ui->lineEdit->setFocusPolicy(Qt::StrongFocus);

}

void Dialog::initStyle()
{
    //设置图标
    QIcon icon(":/images/images/clip.png");
    setWindowIcon(icon);

    //设置字体
    QFontDatabase fontDatabase;
    QString fontPath = ":/font/font/LXGWWenKaiMono-Light.ttf";  // 从资源文件中获取字体路径
    int fontId = fontDatabase.addApplicationFont(fontPath);

    if (fontId != -1) {
        QString family = fontDatabase.applicationFontFamilies(fontId).at(0);
        qDebug() << "Loaded font family:" << family;
        QFont font(family);
        ui->tabWidget->setFont(font);
        ui->listWidget->setFont(font);
        ui->lineEdit->setFont(font);
    } else {
        qDebug() << "Failed to load font.";
    }

    //listWidget 窗口铺满 tabWidget
    ui->widget->setLayout(ui->verticalLayout);
    ui->verticalLayout->setContentsMargins(0, 0, 0, 0);
    ui->verticalLayout->setSpacing(0);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(ui->widget);
    setLayout(mainLayout);

    QWidget *tabPage = ui->tabWidget->widget(0);  // 获取第一个选项卡的 QWidget（假设 listWidget 在第一个 tab 中）
    QVBoxLayout *layout = new QVBoxLayout(tabPage);  // 创建一个垂直布局，绑定到选项卡页上
    layout->addWidget(ui->listWidget);  // 将 listWidget 添加到布局中
    layout->setContentsMargins(0, 0, 0, 0);  // 设置边距为 0，确保完全铺满
    tabPage->setLayout(layout);  // 应用布局

    // 设置无边框窗口
    setWindowFlags(Qt::FramelessWindowHint | Qt::ToolTip);
    setAttribute(Qt::WA_ShowWithoutActivating, true);

    //初始化搜索栏
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &Dialog::do_searchData);

    //设置listwidget不可编辑
    ui->listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //布局拉伸铺满窗口
    ui->lineEdit->setMinimumHeight(35);
    ui->toolButton->setMinimumHeight(35);
    ui->toolButton->setMaximumWidth(35);

    //按键聚焦搜索框
    ui->lineEdit->setFocusPolicy(Qt::StrongFocus);

}

void Dialog::do_clipboardDataChanged()
{
    const QMimeData *mimeData = m_clipboard->mimeData();
    QString time = QDateTime::currentDateTime().toString();
    if(clipReady != true){
        if (mimeData->hasImage()) {
            QImage image = qvariant_cast<QImage>(mimeData->imageData());
            QListWidgetItem *item = new QListWidgetItem;
            item->setIcon(QPixmap::fromImage(image));  // fromImage():将QImage 转换为 QPixmap
            item->setData(Qt::UserRole, QVariant::fromValue(image));

            item->setSizeHint(QSize(300, 50));
            ui->listWidget->setIconSize(QSize(300, 50));
            ui->listWidget->insertItem(0, item);
            int id = m_db->dataBaseInsertData("Main", "image", item, time);
            item->setData(Qt::UserRole+1, id);
            item->setToolTip("Time: " + time);
        }
        else if (mimeData->hasText())
        {
            QString text = mimeData->text();
            QListWidgetItem *item = new QListWidgetItem;
            item->setText(text);
            item->setSizeHint(QSize(300, 50));
            ui->listWidget->insertItem(0, item);
            int id = m_db->dataBaseInsertData("Main", "text", item, time);
            item->setData(Qt::UserRole+1, id);
            item->setToolTip(text + "\n\n"+ "Time: " + time);
        }
    }else {
        clipReady = false;
    }
}

void Dialog::do_trayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if (reason == QSystemTrayIcon::DoubleClick) {
        qDebug() << "do do_trayIconActivated";
        showNormal();
        activateWindow(); // 激活窗口
    }
}

void Dialog::do_searchData(const QString &searchText)
{
    // 清空 QListWidget 中的现有数据
    ui->listWidget->clear();

    if (searchText.isEmpty()) {
        loadTableDataIntoTab("Main");  //重新加载回数据
        return;  // 返回，跳过后续的数据库查询
    }

    // 从数据库执行搜索并获取结果
    QList<QListWidgetItem*> searchResults = m_db->getSearchData(searchText);

    // 将查询结果插入到 QListWidget 中
    for (QListWidgetItem *item : searchResults) {
        ui->listWidget->addItem(item);
    }
}

void Dialog::do_listWidget_itemCopyToClip(QListWidgetItem *item)
{
    if (!item) return;

    // 检查item是否有文本数据
    if (!item->text().isEmpty()) {
        // 将文本数据复制到剪贴板
        m_clipboard->setText(item->text());
    }
    // 检查item是否有图标（图像）数据
    else if (!item->icon().isNull())
    {
        QImage image = item->data(Qt::UserRole).value<QImage>();
        // 将图像复制到剪贴板
        m_clipboard->setImage(image);
    }

    hide();
}

void Dialog::do_toggleWindow()
{
    if (isHidden()) {
        // 获取当前鼠标位置
        QPoint globalPos = QCursor::pos();

        // 获取屏幕的可用区域
        QRect screenRect = QApplication::primaryScreen()->availableGeometry();

        // 计算窗口的新位置，使其在屏幕边缘显示
        int newX = globalPos.x() - width() / 2;
        int newY = globalPos.y() - height() / 2;

        // 确保窗口不会超出屏幕左边缘
        if (newX < screenRect.left()) {
            newX = screenRect.left();
        }
        // 确保窗口不会超出屏幕右边缘
        if (newX + width() > screenRect.right()) {
            newX = screenRect.right() - width();
        }
        // 确保窗口不会超出屏幕顶部边缘
        if (newY < screenRect.top()) {
            newY = screenRect.top();
        }
        // 确保窗口不会超出屏幕底部边缘
        if (newY + height() > screenRect.bottom()) {
            newY = screenRect.bottom() - height();
        }
        // 移动窗口到新的位置
        move(newX, newY);

        showNormal();  // 如果最小化了，恢复窗口
        activateWindow(); // 激活窗口
    } else {
        hide();  // 否则最小化到托盘
    }
}

void Dialog::do_showMainTableMenu()
{
    m_contextMenu = new QMenu;
    m_contextMenu->addAction(ui->actCreateGroup);
    m_contextMenu->addAction(ui->actMove2Grop);
    m_contextMenu->exec(QCursor::pos());
}

void Dialog::do_showSubTableMenu()
{
    m_subTabMenu = new QMenu;
    m_subTabMenu->addAction(ui->actRemoveItem);
    m_subTabMenu->exec(QCursor::pos());
}

bool Dialog::eventFilter(QObject *watched, QEvent *event)
{
    // 检查是否是 listWidget 捕获的事件，并且是 KeyPress 事件
    if (event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);

        // 如果输入了字符，转移焦点到 lineEdit
        if (keyEvent->key() >= Qt::Key_Space && keyEvent->key() <= Qt::Key_AsciiTilde)
        {
            ui->lineEdit->setFocus();
            // return true; // 拦截事件，防止继续传递
        }
    }
    if(QEvent::WindowDeactivate == event->type() && ignoreDeact)
    {
        hide();
    }
    // 继续执行父类的事件处理
    return QDialog::eventFilter(watched, event);
}

void Dialog::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "keyPressEvent";
    // 如果输入了任何字符
    int currentTabIndex = ui->tabWidget->currentIndex();
    int tabCount = ui->tabWidget->count();
    if (event->key() >= Qt::Key_Space && event->key() <= Qt::Key_AsciiTilde)
    {
        ui->lineEdit->setFocus();
    }
    else
    {
        switch (event->key())
        {
        case Qt::Key_Up:
        case Qt::Key_Down:
            if (currentTabIndex != -1)
            {
                QWidget *currentTab = ui->tabWidget->widget(currentTabIndex);
                QListWidget *currentListWidget = currentTab->findChild<QListWidget*>();
                if (currentListWidget)
                {
                    currentListWidget->setFocus();
                }
            }
            break;
        case Qt::Key_Left:
            if (currentTabIndex > 0)
            {
                ui->tabWidget->setCurrentIndex(currentTabIndex - 1);
            }
            break;
        case Qt::Key_Right:
            if (currentTabIndex < tabCount - 1)
            {
                ui->tabWidget->setCurrentIndex(currentTabIndex + 1);
            }
            break;
        case Qt::Key_Enter:
        case Qt::Key_Return:
            // on_listWidget_itemDoubleClicked();
            if (currentTabIndex != -1)
            {
                QWidget *currentTab = ui->tabWidget->widget(currentTabIndex);
                QListWidget *currentListWidget = currentTab->findChild<QListWidget*>();
                if (currentListWidget)
                {
                    QListWidgetItem *selectedItem = currentListWidget->currentItem();
                    if (selectedItem)
                    {
                        qDebug() << "Selected item currentTabIndex" << currentTabIndex;
                        if(currentTabIndex == 0)
                            on_listWidget_itemDoubleClicked(selectedItem);
                        else
                            do_listWidget_itemCopyToClip(selectedItem);
                    }
                    else
                    {
                        qDebug() << "No item is currently selected.";
                    }
                }
            }
            break;
        default:
            break;
        }
    }

    // 调用父类的事件处理器，以确保其它键盘事件正常处理
    QWidget::keyPressEvent(event);
}

void Dialog::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    // 断开信号与槽的连接
    clipReady = true;
    if (!item) return;
    int currentRow = ui->listWidget->row(item);

    // 检查item是否有文本数据
    if (!item->text().isEmpty()) {
        // 将文本数据复制到剪贴板
        m_clipboard->setText(item->text());
    }
    // 检查item是否有图标（图像）数据
    else if (!item->icon().isNull())
    {
        QImage image = item->data(Qt::UserRole).value<QImage>();
        // 将图像复制到剪贴板
        m_clipboard->setImage(image);
    }

    QListWidgetItem *movedItem = ui->listWidget->takeItem(currentRow);
    // 将该项插入到列表的顶部
    ui->listWidget->insertItem(0, movedItem);
    // 可选：重新设置当前项为插入的项
    ui->listWidget->setCurrentItem(movedItem);
    hide();
}

QWidget* Dialog::findTabByName(const QString &tabName)
{
    for (int i = 0; i < ui->tabWidget->count(); ++i) {
        if (ui->tabWidget->tabText(i) == tabName) {
            return ui->tabWidget->widget(i);
        }
    }
    return nullptr; // 没有找到时返回空指针
}

void Dialog::loadTableDataIntoTab(const QString &tableName)
{
    // 查找或创建对应的 tab 和 listWidget
    int tabIndex = ui->tabWidget->indexOf(findTabByName(tableName));
    QListWidget *listWidget = nullptr;

    if (tabIndex == -1) {
        // 创建新的 tab 和 listWidget
        QWidget *newTab = new QWidget();
        listWidget = new QListWidget();
        QVBoxLayout *layout = new QVBoxLayout(newTab);
        QString listWidgetStyle = ui->listWidget->styleSheet();
        listWidget->installEventFilter(this);
        listWidget->setStyleSheet(listWidgetStyle);
        layout->setContentsMargins(0, 0, 0, 0);
        layout->addWidget(listWidget);
        newTab->setLayout(layout);
        ui->tabWidget->addTab(newTab, tableName);
        listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(listWidget, SIGNAL(customContextMenuRequested(QPoint)),this, SLOT(do_showSubTableMenu()));
        connect(listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(do_listWidget_itemCopyToClip()));
    } else {
        // 获取已有的 listWidget
        QWidget *tab = ui->tabWidget->widget(tabIndex);
        listWidget = tab->findChild<QListWidget*>();
    }

    if (listWidget) {
        listWidget->clear();
        listWidget->setIconSize(QSize(300, 50));

        // 从数据库加载数据并显示在 listWidget 中
        QList<QListWidgetItem*> items = m_db->getTableData(tableName);
        for (QListWidgetItem *item : items) {
            listWidget->addItem(item);
        }
    }
}

QListWidget* Dialog::getListWidgetFromTab(int tabIndex)
{
    // 获取指定索引的 tab 页面
    QWidget* tabPage = ui->tabWidget->widget(tabIndex);

    if (!tabPage) {
        qDebug() << "No tab page at index:" << tabIndex;
        return nullptr;
    }

    // 遍历 tabPage 中的所有子控件
    for (QObject* child : tabPage->children()) {
        QListWidget* listWidget = qobject_cast<QListWidget*>(child);
        if (listWidget) {
            return listWidget; // 找到并返回 QListWidget
        }
    }

    qDebug() << "No QListWidget found in tab at index:" << tabIndex;
    return nullptr;
}


void Dialog::on_actClearDB_triggered()
{
    m_db->dataBaseRemoveDB();
}


void Dialog::on_actExit_triggered()
{
    QApplication::quit();
}


void Dialog::on_actReloadDB_triggered()
{
    QStringList tableNames = m_db->getAllTableNames();
    for (const QString &tableName : tableNames) {
        loadTableDataIntoTab(tableName);
    }
}

void Dialog::on_actCreateGroup_triggered()
{
    QString dlgTitle= "新建组";
    QString txtLabel= "输入新建组名";
    QString iniInput= "new";
    QLineEdit::EchoMode echoMode= QLineEdit::Normal; //正常文字输入
    bool ok= false;
    ignoreDeact = false;
    QString text = QInputDialog::getText(this, dlgTitle, txtLabel, echoMode, iniInput, &ok);
    ignoreDeact = true;
    if (ok && !text.isEmpty())
    {
        qDebug() << "Create a new Group";
        if(m_db->dataBaseCreateTable(text))
        {
            QWidget *newTab = new QWidget();
            QListWidget *newListWidget = new QListWidget();
            QVBoxLayout *layout = new QVBoxLayout(newTab);
            layout->setContentsMargins(0, 0, 0, 0);
            layout->addWidget(newListWidget);
            newTab->setLayout(layout);
            QString listWidgetStyle = ui->listWidget->styleSheet();
            newListWidget->installEventFilter(this);
            newListWidget->setStyleSheet(listWidgetStyle);
            ui->tabWidget->addTab(newTab, text);
            qDebug() << "Create Group succeed";
            newListWidget->setContextMenuPolicy(Qt::CustomContextMenu);
            connect(newListWidget, SIGNAL(customContextMenuRequested(QPoint)),this, SLOT(do_showSubTableMenu()));
            connect(newListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(do_listWidget_itemCopyToClip()));
        }
        else
        {
            qDebug() << "Create Group (" << text << ") failed";
        }
    }
}


void Dialog::on_actMove2Grop_triggered()
{
    QString dlgTitle= "移动到组";
    QStringList tableNames = m_db->getAllTableNames();
    tableNames.removeAt(0);
    QListWidgetItem *currentItem = ui->listWidget->currentItem();
    QString textItem = currentItem->text();
    QVariant imageItem = currentItem->data(Qt::UserRole);
    QString time = QDateTime::currentDateTime().toString();
    QString txtLabel= "请选择组";
    bool ok= false;
    ignoreDeact = false;
    QString tableName = QInputDialog::getItem(this, dlgTitle, txtLabel, tableNames, 0, false, &ok);
    ignoreDeact = true;
    int tableIndex = tableNames.indexOf(tableName) + 1;
    if (ok && !tableName.isEmpty())
    {
        qDebug() << tableName;
        if (!currentItem) {
            qDebug() << "No item selected.";
            return;
        }
        ui->tabWidget->setCurrentIndex(tableIndex);
        QListWidget* listWidget = getListWidgetFromTab(tableIndex);
        if(listWidget)
        {
            qDebug() << "Successfully found QListWidget in tab at index:" << tableIndex;
        }

        if(!textItem.isNull())
        {
            qDebug() << "text item";
            QListWidgetItem *item = new QListWidgetItem;
            item->setText(textItem);
            item->setSizeHint(QSize(300, 50));
            listWidget->insertItem(0, item);
            int insertedId = m_db->dataBaseInsertData(tableName, "text", item, time);
            item->setData(Qt::UserRole + 1, insertedId);
            item->setToolTip(textItem + "\n\n"+ "Time: " + time);
        }
        else if (!imageItem.isNull())
        {
            qDebug() << "image item";
            QListWidgetItem *item = new QListWidgetItem;
            QImage image = imageItem.value<QImage>();
            item->setIcon(QPixmap::fromImage(image));
            item->setData(Qt::UserRole, QVariant::fromValue(image));
            item->setSizeHint(QSize(300, 50));
            listWidget->setIconSize(QSize(300, 50));
            listWidget->insertItem(0, item);
            int insertedId = m_db->dataBaseInsertData(tableName, "image", item, time);
            item->setData(Qt::UserRole + 1, insertedId);
            item->setToolTip("Time: " + time);
        }
        else {
            qDebug() << "Unsupported data type.";
        }
    }
}


void Dialog::on_actRemoveItem_triggered()
{
    // 获取当前选中的 tab
    int currentTabIndex = ui->tabWidget->currentIndex();
    if (currentTabIndex == -1) {
        qDebug() << "No tab is currently selected.";
        return;
    }

    // 获取当前 tab 的名称
    QString currentTabName = ui->tabWidget->tabText(currentTabIndex);
    qDebug() << "Current Tab Name: " << currentTabName;

    // 获取当前 tab 内的 QListWidget
    QWidget *currentTab = ui->tabWidget->widget(currentTabIndex);
    QListWidget *currentListWidget = currentTab->findChild<QListWidget*>();

    if (!currentListWidget) {
        qDebug() << "No QListWidget found in the current tab.";
        return;
    }

    // 获取当前选中的 QListWidgetItem
    QListWidgetItem *selectedItem = currentListWidget->currentItem();
    if (!selectedItem) {
        qDebug() << "No item selected in the current list.";
        return;
    }

    // 获取 QListWidgetItem 的 UserData (UserRole)
    QVariant userData = selectedItem->data(Qt::UserRole+1);
    int id = userData.toInt();
    qDebug() << "Selected Item UserData: " << userData;

    // 删除该项
    int row = currentListWidget->row(selectedItem);
    delete currentListWidget->takeItem(row);  // takeItem 返回指针，delete 释放内存

    qDebug() << "Item removed successfully from " << currentTabName;

    m_db->dataBaseRemoveTableItem(currentTabName, id);
}



void Dialog::on_actRemoveGroup_triggered()
{
    QString dlgTitle= "删除组";
    QStringList tableNames = m_db->getAllTableNames();
    tableNames.removeAt(0);
    QString txtLabel= "请选择组";
    bool ok= false;
    ignoreDeact = false;
    QString tableName = QInputDialog::getItem(this, dlgTitle, txtLabel, tableNames, 0, false, &ok);
    ignoreDeact = true;
    int tableIndex = tableNames.indexOf(tableName) + 1;
    if (ok && !tableName.isEmpty())
    {
        // 删除表
        if (m_db->dataBaseRemoveTable(tableName)) {
            // 在 UI 中删除 tab
            if (tableIndex != -1) {
                ui->tabWidget->removeTab(tableIndex);
            }
            qDebug() << "Group removed successfully:" << tableName;
        }
        else {
            qDebug() << "Failed to remove group:" << tableName;
        }
    }
}


void Dialog::on_actShortCut_triggered()
{
    ignoreDeact = false;
    QKeySequenceEdit *keySequenceEdit = new QKeySequenceEdit(this);
    keySequenceEdit->setKeySequence(m_gobalRun->shortcut());

    QDialog dialog(this);
    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    layout->addWidget(keySequenceEdit);
    QPushButton *okButton = new QPushButton("OK", &dialog);
    QPushButton *cancelButton = new QPushButton("Cancel", &dialog);
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    layout->addLayout(buttonLayout);
    dialog.setLayout(layout);

    // 连接按钮的信号槽
    connect(okButton, &QPushButton::clicked, [&]() {
        QString newShortCut = keySequenceEdit->keySequence().toString();
        qDebug() << "change short cut: " << newShortCut;
        m_gobalRun->setShortcut(QKeySequence(newShortCut), true);
        dialog.accept();
    });

    connect(cancelButton, &QPushButton::clicked, [&]() {
        dialog.reject();
    });

    // 显示对话框VV
    dialog.exec();
    ignoreDeact = true;
}


void Dialog::on_actHelp_triggered()
{
    ignoreDeact = false;

    QDialog *helpDialog = new QDialog(this);

    ui_help->setupUi(helpDialog);

    this->setLayout(ui_help->verticalLayout);

    QFont fontTitle = ui_help->labTitle->font();      // 获取当前字体
    fontTitle.setPointSize(16);
    ui_help->labTitle->setFont(fontTitle);
    QFont fontMark = ui_help->labTitle->font();
    fontMark.setPointSize(12);
    ui_help->labMark->setFont(fontMark);

    QFont fontPlain = ui_help->textBrowser->font();
    fontPlain.setPointSize(10);
    ui_help->textBrowser->setFont(fontPlain);
    ui_help->textBrowser->setReadOnly(true);



    // 使用 exec() 而不是 show()，以阻塞模式显示对话框
    helpDialog->exec();
    ignoreDeact = true;

}

