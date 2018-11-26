/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *inputLabel;
    QLabel *detectLabel;
    QPushButton *openCameraBtn;
    QPushButton *exitBtn;
    QPushButton *recognitionBtn;
    QPushButton *addFaceBtn;
    QLabel *peopleLabel;
    QLabel *facesLabel;
    QLabel *nameLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(969, 619);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inputLabel = new QLabel(centralWidget);
        inputLabel->setObjectName(QStringLiteral("inputLabel"));
        inputLabel->setGeometry(QRect(40, 30, 351, 261));
        detectLabel = new QLabel(centralWidget);
        detectLabel->setObjectName(QStringLiteral("detectLabel"));
        detectLabel->setGeometry(QRect(540, 30, 351, 261));
        openCameraBtn = new QPushButton(centralWidget);
        openCameraBtn->setObjectName(QStringLiteral("openCameraBtn"));
        openCameraBtn->setGeometry(QRect(50, 340, 111, 41));
        exitBtn = new QPushButton(centralWidget);
        exitBtn->setObjectName(QStringLiteral("exitBtn"));
        exitBtn->setGeometry(QRect(50, 420, 111, 41));
        recognitionBtn = new QPushButton(centralWidget);
        recognitionBtn->setObjectName(QStringLiteral("recognitionBtn"));
        recognitionBtn->setGeometry(QRect(520, 340, 131, 41));
        addFaceBtn = new QPushButton(centralWidget);
        addFaceBtn->setObjectName(QStringLiteral("addFaceBtn"));
        addFaceBtn->setGeometry(QRect(520, 420, 131, 41));
        peopleLabel = new QLabel(centralWidget);
        peopleLabel->setObjectName(QStringLiteral("peopleLabel"));
        peopleLabel->setGeometry(QRect(190, 350, 151, 20));
        facesLabel = new QLabel(centralWidget);
        facesLabel->setObjectName(QStringLiteral("facesLabel"));
        facesLabel->setGeometry(QRect(190, 430, 151, 20));
        nameLabel = new QLabel(centralWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setGeometry(QRect(690, 350, 171, 20));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 969, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        inputLabel->setText(QApplication::translate("MainWindow", "input", 0));
        detectLabel->setText(QApplication::translate("MainWindow", "detect", 0));
        openCameraBtn->setText(QApplication::translate("MainWindow", "Open Camera", 0));
        exitBtn->setText(QApplication::translate("MainWindow", "Close App", 0));
        recognitionBtn->setText(QApplication::translate("MainWindow", "Face recognition", 0));
        addFaceBtn->setText(QApplication::translate("MainWindow", "Add New Face", 0));
        peopleLabel->setText(QApplication::translate("MainWindow", "number of people:  0 ", 0));
        facesLabel->setText(QApplication::translate("MainWindow", "number of faces:  0 ", 0));
        nameLabel->setText(QApplication::translate("MainWindow", "name:  whose name ?? ", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
