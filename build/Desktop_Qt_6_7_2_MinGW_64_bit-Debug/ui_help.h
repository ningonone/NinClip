/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Help
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labPic;
    QLabel *labTitle;
    QTextBrowser *textBrowser;
    QLabel *labMark;

    void setupUi(QDialog *Help)
    {
        if (Help->objectName().isEmpty())
            Help->setObjectName("Help");
        Help->resize(431, 300);
        layoutWidget = new QWidget(Help);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 20, 391, 261));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        labPic = new QLabel(layoutWidget);
        labPic->setObjectName("labPic");
        QFont font;
        font.setPointSize(16);
        labPic->setFont(font);
        labPic->setPixmap(QPixmap(QString::fromUtf8(":/images/images/clip.ico")));

        horizontalLayout->addWidget(labPic);

        labTitle = new QLabel(layoutWidget);
        labTitle->setObjectName("labTitle");
        labTitle->setTextFormat(Qt::AutoText);
        labTitle->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labTitle);


        verticalLayout->addLayout(horizontalLayout);

        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName("textBrowser");

        verticalLayout->addWidget(textBrowser);

        labMark = new QLabel(layoutWidget);
        labMark->setObjectName("labMark");
        labMark->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(labMark);


        retranslateUi(Help);

        QMetaObject::connectSlotsByName(Help);
    } // setupUi

    void retranslateUi(QDialog *Help)
    {
        Help->setWindowTitle(QCoreApplication::translate("Help", "Dialog", nullptr));
        labPic->setText(QString());
        labTitle->setText(QCoreApplication::translate("Help", "NinClip -- \345\277\253\346\215\267\345\210\206\347\273\204\345\211\252\350\264\264\346\235\277\345\267\245\345\205\267", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("Help", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">\344\270\273\350\246\201\345\212\237\350\203\275\357\274\232</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- "
                        "\350\207\252\345\212\250\350\216\267\345\217\226\345\211\252\350\264\264\346\235\277\346\225\260\346\215\256\357\274\214\346\224\257\346\214\201\346\226\207\346\234\254\345\222\214\345\233\276\347\211\207\343\200\202</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- \346\226\271\345\220\221\351\224\256\345\217\257\344\273\245\345\210\207\346\215\242\351\200\211\344\270\255\351\241\271\345\222\214\347\273\204\357\274\214\345\233\236\350\275\246\346\210\226\350\200\205\345\217\214\345\207\273\345\215\263\345\244\215\345\210\266\345\206\205\345\256\271\345\210\260\345\211\252\350\264\264\346\235\277\343\200\202</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
""
                        "<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- \346\224\257\346\214\201\345\277\253\346\215\267\351\224\256\345\224\244\351\206\222\357\274\214\345\224\244\351\206\222\344\275\215\347\275\256\350\267\237\351\232\217\351\274\240\346\240\207\357\274\214\351\273\230\350\256\244\345\277\253\346\215\267\351\224\256\344\270\272Ctrl + Alt  +W</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- \346\211\200\346\234\211\346\225\260\346\215\256\351\203\275\344\274\232\345\255\230\346\224\276\345\210\260\346\225\260\346\215\256\345\272\223</p></body></html>", nullptr));
        labMark->setText(QCoreApplication::translate("Help", "Make by NINGO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Help: public Ui_Help {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
