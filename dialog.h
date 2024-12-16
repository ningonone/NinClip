#ifndef DIALOG_H
#define DIALOG_H

#include "database.h"

#include <QMenu>
#include <QDialog>
#include <QKeyEvent>
#include <QListWidget>
#include <QClipboard>
#include <QHotkey>
#include <QShortcut>
#include <QFocusEvent>
#include <QSystemTrayIcon>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
class Help;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

private:
    Database        *m_db;
    QListWidget     *m_listWidget;
    QClipboard      *m_clipboard;
    QMenu           *m_menu;
    QMenu           *m_contextMenu;
    QMenu           *m_subTabMenu;
    QShortcut       *m_shortcut;
    QSystemTrayIcon *m_trayIcon;
    QHotkey         *m_gobalRun;
    bool            clipReady;
    bool            ignoreDeact = true;
    QStringList     TABLE_NAMES;

    void initDialog();

    void initStyle();

    void loadTableDataIntoTab(const QString &tableName);

    QWidget* findTabByName(const QString &tabName);

    QListWidget* getListWidgetFromTab(int tabIndex);

    void do_listWidget_itemCopyToClip(QListWidgetItem *item);

protected:
    void keyPressEvent(QKeyEvent *event);

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void do_clipboardDataChanged();

    void do_trayIconActivated(QSystemTrayIcon::ActivationReason reason);

    void do_toggleWindow();

    void do_showMainTableMenu();

    void do_showSubTableMenu();

    void do_searchData(const QString &searchText);

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_actClearDB_triggered();

    void on_actExit_triggered();

    void on_actReloadDB_triggered();

    void on_actCreateGroup_triggered();

    void on_actMove2Grop_triggered();

    void on_actRemoveItem_triggered();

    void on_actRemoveGroup_triggered();

    void on_actShortCut_triggered();

    void on_actHelp_triggered();

private:
    Ui::Dialog *ui;
    Ui::Help *ui_help;
};
#endif // DIALOG_H
