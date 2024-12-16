/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QAction *actClearDB;
    QAction *actBackupDB;
    QAction *actExit;
    QAction *actReloadDB;
    QAction *actMove2Grop;
    QAction *actCreateGroup;
    QAction *actRemoveItem;
    QAction *actRemoveGroup;
    QAction *actShortCut;
    QAction *actHelp;
    QWidget *widget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QToolButton *toolButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->setWindowModality(Qt::NonModal);
        Dialog->setEnabled(true);
        Dialog->resize(927, 730);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMaximumSize(QSize(16777208, 16777215));
        QFont font;
        font.setFamilies({QString::fromUtf8("Space Mono")});
        font.setPointSize(14);
        Dialog->setFont(font);
        Dialog->setContextMenuPolicy(Qt::DefaultContextMenu);
        Dialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    font-size: 14pt; /* \345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"    background-color: #E6E6FA;  /* \346\232\227\350\260\203\347\232\204\346\265\205\350\223\235\350\211\262\357\274\210\350\226\260\350\241\243\350\215\211\350\211\262\357\274\211 */\n"
"    border: 3px solid #4B0082;  /* \346\232\227\347\264\253\350\211\262\347\273\206\347\272\277\346\241\206 */\n"
"\n"
"}\n"
"\n"
"QDialog * {\n"
"    font-family: 'Space Mono', monospace; /* \351\273\230\350\256\244\345\255\227\344\275\223\357\274\210\350\213\261\346\226\207\357\274\211 */\n"
"}\n"
"\n"
"QDialog QWidget {\n"
"    font-family: 'LXGW WenKai', serif; /* \344\270\255\346\226\207\345\255\227\344\275\223 */\n"
"}"));
        actClearDB = new QAction(Dialog);
        actClearDB->setObjectName("actClearDB");
        actClearDB->setMenuRole(QAction::NoRole);
        actBackupDB = new QAction(Dialog);
        actBackupDB->setObjectName("actBackupDB");
        actBackupDB->setMenuRole(QAction::NoRole);
        actExit = new QAction(Dialog);
        actExit->setObjectName("actExit");
        actExit->setMenuRole(QAction::NoRole);
        actReloadDB = new QAction(Dialog);
        actReloadDB->setObjectName("actReloadDB");
        actReloadDB->setMenuRole(QAction::NoRole);
        actMove2Grop = new QAction(Dialog);
        actMove2Grop->setObjectName("actMove2Grop");
        actMove2Grop->setMenuRole(QAction::NoRole);
        actCreateGroup = new QAction(Dialog);
        actCreateGroup->setObjectName("actCreateGroup");
        actCreateGroup->setMenuRole(QAction::NoRole);
        actRemoveItem = new QAction(Dialog);
        actRemoveItem->setObjectName("actRemoveItem");
        actRemoveItem->setMenuRole(QAction::NoRole);
        actRemoveGroup = new QAction(Dialog);
        actRemoveGroup->setObjectName("actRemoveGroup");
        actRemoveGroup->setMenuRole(QAction::NoRole);
        actShortCut = new QAction(Dialog);
        actShortCut->setObjectName("actShortCut");
        actShortCut->setMenuRole(QAction::NoRole);
        actHelp = new QAction(Dialog);
        actHelp->setObjectName("actHelp");
        actHelp->setMenuRole(QAction::NoRole);
        widget = new QWidget(Dialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(220, 80, 641, 591));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 10, 551, 511));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(3);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName("tabWidget");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("LXGW WenKai")});
        font1.setPointSize(10);
        tabWidget->setFont(font1);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    border: 1px solid #cccccc;\n"
"    background: white;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background: #e0e0e0;\n"
"    border: 1px solid #cccccc;\n"
"    padding: 5px 10px;\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background: white;\n"
"    border-bottom-color: white;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName("tab");
        listWidget = new QListWidget(tab);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 10, 561, 391));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("LXGW WenKai")});
        font2.setPointSize(9);
        listWidget->setFont(font2);
        listWidget->setStyleSheet(QString::fromUtf8("QListWidget {\n"
"    background-color: white;\n"
"    border: 1px solid #E0E0E0;\n"
"    border-radius: 5px;\n"
"    outline: 0;  /* \347\247\273\351\231\244\347\204\246\347\202\271\346\227\266\347\232\204\350\275\256\345\273\223 */\n"
"}\n"
"\n"
"QListWidget::item {\n"
"    padding: 10px;\n"
"    border-bottom: 1px solid #E0E0E0;\n"
"    color: #333333;\n"
"}\n"
"\n"
"QListWidget::item:last {\n"
"    border-bottom: none;\n"
"}\n"
"\n"
"QListWidget::item:hover {\n"
"    background-color: #F5F5F5;\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background-color: #E8F0FE;\n"
"    color: #1a73e8;\n"
"    border: none;  /* \347\247\273\351\231\244\351\200\211\344\270\255\351\241\271\347\232\204\350\276\271\346\241\206 */\n"
"}\n"
"\n"
"QListWidget::item:focus {\n"
"    border: none;  /* \347\247\273\351\231\244\347\204\246\347\202\271\351\241\271\347\232\204\350\276\271\346\241\206 */\n"
"    outline: none;  /* \347\247\273\351\231\244\347\204\246\347\202\271\351\241\271\347\232\204\350\275\256\345\273\223 */"
                        "\n"
"}\n"
"\n"
"QListWidget::item:selected:active {\n"
"    background-color: #D2E3FC;\n"
"    border: none;  /* \347\241\256\344\277\235\346\264\273\345\212\250\351\200\211\344\270\255\351\241\271\344\271\237\346\262\241\346\234\211\350\276\271\346\241\206 */\n"
"}\n"
"\n"
"QListWidget QScrollBar:vertical {\n"
"    border: none;\n"
"    background: white;\n"
"    width: 8px;\n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"\n"
"QListWidget QScrollBar::handle:vertical {\n"
"    background: #BDBDBD;\n"
"    min-height: 20px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QListWidget QScrollBar::add-line:vertical, QListWidget QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}"));
        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName("lineEdit");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font3.setPointSize(10);
        lineEdit->setFont(font3);
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: 1px solid #A0A0A0; /* \350\276\271\346\241\206\345\256\275\345\272\246\344\270\2721px\357\274\214\351\242\234\350\211\262\344\270\272#A0A0A0 */\n"
"	border-radius: 3px; /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"	padding-left: 5px; /* \346\226\207\346\234\254\350\267\235\347\246\273\345\267\246\350\276\271\347\225\214\346\234\2115px */\n"
"	background-color: #F2F2F2; /* \350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"	color: #A0A0A0; /* \346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"	selection-background-color: #A0A0A0; /* \351\200\211\344\270\255\346\226\207\346\234\254\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"	selection-color: #F2F2F2; /* \351\200\211\344\270\255\346\226\207\346\234\254\347\232\204\351\242\234\350\211\262 */\n"
"	font-family: \"Microsoft YaHei\"; /* \346\226\207\346\234\254\345\255\227\344\275\223\346\227\217 */\n"
"	font-size: 10pt; /* \346\226\207\346\234\254\345\255\227\344\275\223\345\244\247\345\260\217 "
                        "*/\n"
"}\n"
"\n"
"QLineEdit:hover { /* \351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QLineEdit\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	border: 1px solid #298DFF;\n"
"	border-radius: 3px;\n"
"	background-color: #FFFFFF;\n"
"	color: #298DFF;\n"
"	selection-background-color: #FFFFFF;\n"
"	selection-color: #FFFFFF;\n"
"}\n"
"\n"
"QLineEdit:focus { /* \351\274\240\346\240\207\346\202\254\346\265\256\345\234\250QLineEdit\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	border: 1px solid #298DFF;\n"
"	border-radius: 3px;\n"
"	background-color: #FFFFFF;\n"
"	color: #298DFF;\n"
"	selection-background-color: #FFFFFF;\n"
"	selection-color: #FFFFFF;\n"
"}\n"
"\n"
"\n"
"QLineEdit[echoMode=\"2\"] { /* QLineEdit\346\234\211\350\276\223\345\205\245\346\216\251\347\240\201\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	lineedit-password-character: 9679;\n"
"	lineedit-password-mask-delay: 2000;\n"
"}\n"
"\n"
"QLineEdit:disabled { /* QLineEdit\345\234\250\347\246\201\347\224\250\346\227"
                        "\266\347\232\204\347\212\266\346\200\201 */\n"
"	border: 1px solid #CDCDCD;\n"
"	background-color: #CDCDCD;\n"
"	color: #B4B4B4;\n"
"}\n"
"\n"
"QLineEdit:read-only { /* QLineEdit\345\234\250\345\217\252\350\257\273\346\227\266\347\232\204\347\212\266\346\200\201 */\n"
"	background-color: #CDCDCD;\n"
"	color: #F2F2F2;\n"
"}"));

        horizontalLayout->addWidget(lineEdit);

        toolButton = new QToolButton(layoutWidget);
        toolButton->setObjectName("toolButton");
        toolButton->setFont(font3);
        toolButton->setStyleSheet(QString::fromUtf8(".QPushButton,.QToolButton{\n"
"	border: 1px solid #A0A0A0; /* \350\276\271\346\241\206\345\256\275\345\272\246\344\270\2721px\357\274\214\351\242\234\350\211\262\344\270\272#A0A0A0 */\n"
"	border-radius: 3px; /* \350\276\271\346\241\206\345\234\206\350\247\222 */\n"
"	background-color: #F2F2F2; /* \350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"	color: #A0A0A0; /* \346\226\207\346\234\254\351\242\234\350\211\262 */\n"
"	selection-background-color: #A0A0A0; /* \351\200\211\344\270\255\346\226\207\346\234\254\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"	selection-color: #F2F2F2; /* \351\200\211\344\270\255\346\226\207\346\234\254\347\232\204\351\242\234\350\211\262 */\n"
"	font-family: \"Microsoft YaHei\"; /* \346\226\207\346\234\254\345\255\227\344\275\223\346\227\217 */\n"
"	font-size: 10pt; /* \346\226\207\346\234\254\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QToolButton::icon {\n"
"    alignment: center;  /* \345\260\206\345\233\276\346\240\207\345\261\205"
                        "\344\270\255 */\n"
"    padding-left: 0px;  /* \345\267\246\344\276\247\345\206\205\350\276\271\350\267\235 */\n"
"    padding-right: 0px;  /* \345\217\263\344\276\247\345\206\205\350\276\271\350\267\235 */\n"
"    margin-left: auto;   /* \350\207\252\345\212\250\345\267\246\350\276\271\350\267\235 */\n"
"    margin-right: auto;  /* \350\207\252\345\212\250\345\217\263\350\276\271\350\267\235 */\n"
"    text-align: center;  /* \345\246\202\346\236\234\346\214\211\351\222\256\346\234\211\346\226\207\346\234\254\357\274\214\350\277\231\351\207\214\344\271\237\346\230\257\345\261\205\344\270\255\346\230\276\347\244\272 */\n"
"}\n"
"\n"
".QPushButton:hover,.QToolButton:hover{\n"
"	border: 1px solid #298DFF;\n"
"	border-radius: 3px;\n"
"	background-color: #FFFFFF;\n"
"	color: #298DFF;\n"
"	selection-background-color: #298DFF;\n"
"	selection-color: #F2F2F2;\n"
"}\n"
"\n"
".QPushButton:pressed,.QToolButton:pressed{\n"
"background:qlineargradient(spread:pad,x1:0,y1:0,x2:0,y2:1,stop:0 #E1E4E6,stop:1 #CCD3D9);\n"
"}\n"
""
                        "\n"
".QToolButton::menu-indicator{\n"
"image:None;\n"
"}\n"
"\n"
"QToolButton#btnMenu,QToolButton#btnTool,QPushButton#btnMenu_Min,QPushButton#btnMenu_Max,QPushButton#btnMenu_Close{\n"
"border-radius:3px;\n"
"color:#000000;\n"
"padding:3px;\n"
"margin:0px;\n"
"background:none;\n"
"border-style:none;\n"
"}\n"
"\n"
"QToolButton#btnMenu:hover,QPushButton#btnMenu_Min:hover,QPushButton#btnMenu_Max:hover{\n"
"color:#FFFFFF;\n"
"margin:1px 1px 2px 1px;\n"
"background-color:rgba(51,127,209,230);\n"
"}\n"
"\n"
"/*QToolButton#btnTool:hover{\n"
"    color:#FFFFFF;\n"
"    margin:1px 1px 2px 1px;\n"
"    background-color:rgba(51,127,209,230);\n"
"}*/\n"
"\n"
"QToolButton#btnTool:hover{  /*\351\274\240\346\240\207\346\224\276\344\270\212\345\220\216*/\n"
"    color:rgb(255, 255, 255);\n"
"    min-height:20;\n"
"    border-style: solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),  stop: 0.3 rgb(160,160,160), "
                        " stop: 1 rgb(120,120,120));\n"
"    border:1px;\n"
"    border-radius:5px;\n"
"    padding:2px 4px;\n"
"}\n"
"\n"
"QToolButton#btnTool:pressed{ /*\346\214\211\344\270\213\346\214\211\351\222\256\345\220\216*/\n"
"    color:rgb(255, 255, 255);\n"
"    min-height:20;\n"
"    border-style:solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),  stop: 0.3 rgb(190,190,190),  stop: 1 rgb(160,160,160));\n"
"    border:1px;\n"
"    border-radius:5px;\n"
"    padding:2px 4px;\n"
"}\n"
"\n"
"QToolButton#btnTool:checked{    /*\351\200\211\344\270\255\345\220\216*/\n"
"    color:rgb(255, 255, 255);\n"
"    min-height:20;\n"
"    border-style:solid;\n"
"    border-top-left-radius:2px;\n"
"    border-top-right-radius:2px;\n"
"    background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 rgb(226,236,241),  stop: 0.3 rgb(190,190,190),  stop: 1 rgb(160,160,160));\n"
"    border:1px;\n"
"    border-radius:5px;\n"
""
                        "    padding:2px 4px;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/blue_down.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton->setIcon(icon);
        toolButton->setPopupMode(QToolButton::InstantPopup);
        toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton->setAutoRaise(true);
        toolButton->setArrowType(Qt::NoArrow);

        horizontalLayout->addWidget(toolButton);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(listWidget, lineEdit);
        QWidget::setTabOrder(lineEdit, toolButton);

        retranslateUi(Dialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "NinClip", nullptr));
        actClearDB->setText(QCoreApplication::translate("Dialog", "\346\270\205\347\251\272\346\225\260\346\215\256\345\272\223", nullptr));
        actBackupDB->setText(QCoreApplication::translate("Dialog", "\345\244\207\344\273\275\346\225\260\346\215\256\345\272\223", nullptr));
        actExit->setText(QCoreApplication::translate("Dialog", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
        actReloadDB->setText(QCoreApplication::translate("Dialog", "\351\207\215\346\226\260\345\212\240\350\275\275\346\225\260\346\215\256\345\272\223", nullptr));
        actMove2Grop->setText(QCoreApplication::translate("Dialog", "\347\247\273\345\212\250\345\210\260\347\273\204", nullptr));
        actCreateGroup->setText(QCoreApplication::translate("Dialog", "\346\226\260\345\273\272\347\273\204", nullptr));
        actRemoveItem->setText(QCoreApplication::translate("Dialog", "\345\210\240\351\231\244\351\241\271", nullptr));
        actRemoveGroup->setText(QCoreApplication::translate("Dialog", "\345\210\240\351\231\244\347\273\204", nullptr));
        actShortCut->setText(QCoreApplication::translate("Dialog", "\345\277\253\346\215\267\351\224\256", nullptr));
        actHelp->setText(QCoreApplication::translate("Dialog", "\345\270\256\345\212\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Dialog", "Main", nullptr));
        toolButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
