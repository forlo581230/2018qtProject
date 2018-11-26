/********************************************************************************
** Form generated from reading UI file 'addfacedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFACEDIALOG_H
#define UI_ADDFACEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFaceDialog
{
public:
    QWidget *centralwidget;
    QLabel *addFaceLabel;
    QPushButton *captureBtn;
    QLabel *label;
    QLineEdit *inputNamelineEdit;
    QPushButton *submitBtn;
    QPushButton *cancelBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddFaceDialog)
    {
        if (AddFaceDialog->objectName().isEmpty())
            AddFaceDialog->setObjectName(QStringLiteral("AddFaceDialog"));
        AddFaceDialog->resize(800, 600);
        centralwidget = new QWidget(AddFaceDialog);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        addFaceLabel = new QLabel(centralwidget);
        addFaceLabel->setObjectName(QStringLiteral("addFaceLabel"));
        addFaceLabel->setGeometry(QRect(220, 50, 341, 231));
        captureBtn = new QPushButton(centralwidget);
        captureBtn->setObjectName(QStringLiteral("captureBtn"));
        captureBtn->setGeometry(QRect(340, 330, 99, 27));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 420, 67, 21));
        inputNamelineEdit = new QLineEdit(centralwidget);
        inputNamelineEdit->setObjectName(QStringLiteral("inputNamelineEdit"));
        inputNamelineEdit->setGeometry(QRect(330, 416, 113, 31));
        submitBtn = new QPushButton(centralwidget);
        submitBtn->setObjectName(QStringLiteral("submitBtn"));
        submitBtn->setGeometry(QRect(490, 490, 99, 27));
        cancelBtn = new QPushButton(centralwidget);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(620, 490, 99, 27));
        AddFaceDialog->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AddFaceDialog);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        AddFaceDialog->setMenuBar(menubar);
        statusbar = new QStatusBar(AddFaceDialog);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AddFaceDialog->setStatusBar(statusbar);

        retranslateUi(AddFaceDialog);

        QMetaObject::connectSlotsByName(AddFaceDialog);
    } // setupUi

    void retranslateUi(QMainWindow *AddFaceDialog)
    {
        AddFaceDialog->setWindowTitle(QApplication::translate("AddFaceDialog", "MainWindow", 0));
        addFaceLabel->setText(QApplication::translate("AddFaceDialog", "AddFaceLabel", 0));
        captureBtn->setText(QApplication::translate("AddFaceDialog", "Capture", 0));
        label->setText(QApplication::translate("AddFaceDialog", "Name", 0));
        submitBtn->setText(QApplication::translate("AddFaceDialog", "OK", 0));
        cancelBtn->setText(QApplication::translate("AddFaceDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class AddFaceDialog: public Ui_AddFaceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFACEDIALOG_H
