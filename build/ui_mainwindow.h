/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionWyj_cie;
    QAction *actionWczytaj;
    QAction *actionPolicz;
    QAction *actionInformacje_2;
    QAction *actionZapisz_tabel;
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTableWidget *tableWidget_2;
    QMenuBar *menuBar;
    QMenu *actionInformacje;
    QMenu *menuPlik;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->resize(1044, 550);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(50);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1000, 550));
        MainWindow->setAutoFillBackground(true);
        actionWyj_cie = new QAction(MainWindow);
        actionWyj_cie->setObjectName(QStringLiteral("actionWyj_cie"));
        actionWczytaj = new QAction(MainWindow);
        actionWczytaj->setObjectName(QStringLiteral("actionWczytaj"));
        actionPolicz = new QAction(MainWindow);
        actionPolicz->setObjectName(QStringLiteral("actionPolicz"));
        actionPolicz->setEnabled(false);
        actionInformacje_2 = new QAction(MainWindow);
        actionInformacje_2->setObjectName(QStringLiteral("actionInformacje_2"));
        actionZapisz_tabel = new QAction(MainWindow);
        actionZapisz_tabel->setObjectName(QStringLiteral("actionZapisz_tabel"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 40, 691, 431));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(100);
        sizePolicy1.setVerticalStretch(50);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        tableWidget->setSizeIncrement(QSize(5, 5));
        tableWidget->setFrameShadow(QFrame::Raised);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setDefaultSectionSize(65);
        tableWidget->horizontalHeader()->setMinimumSectionSize(50);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(true);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        tableWidget->verticalHeader()->setMinimumSectionSize(21);
        tableWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 89, 25));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 10, 89, 25));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 10, 89, 25));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(320, 10, 89, 25));
        tableWidget_2 = new QTableWidget(centralWidget);
        if (tableWidget_2->columnCount() < 2)
            tableWidget_2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setEnabled(true);
        tableWidget_2->setGeometry(QRect(710, 40, 321, 431));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(50);
        sizePolicy2.setVerticalStretch(50);
        sizePolicy2.setHeightForWidth(tableWidget_2->sizePolicy().hasHeightForWidth());
        tableWidget_2->setSizePolicy(sizePolicy2);
        tableWidget_2->setMidLineWidth(0);
        tableWidget_2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_2->setTabKeyNavigation(false);
        tableWidget_2->setProperty("showDropIndicator", QVariant(false));
        tableWidget_2->setDragDropOverwriteMode(false);
        tableWidget_2->setCornerButtonEnabled(true);
        tableWidget_2->setColumnCount(2);
        tableWidget_2->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget_2->horizontalHeader()->setDefaultSectionSize(50);
        tableWidget_2->horizontalHeader()->setStretchLastSection(true);
        tableWidget_2->verticalHeader()->setDefaultSectionSize(25);
        MainWindow->setCentralWidget(centralWidget);
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        tableWidget_2->raise();
        tableWidget->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1044, 22));
        actionInformacje = new QMenu(menuBar);
        actionInformacje->setObjectName(QStringLiteral("actionInformacje"));
        actionInformacje->setEnabled(true);
        actionInformacje->setContextMenuPolicy(Qt::NoContextMenu);
        actionInformacje->setAcceptDrops(false);
        actionInformacje->setTearOffEnabled(false);
        actionInformacje->setSeparatorsCollapsible(false);
        actionInformacje->setToolTipsVisible(true);
        menuPlik = new QMenu(menuBar);
        menuPlik->setObjectName(QStringLiteral("menuPlik"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuPlik->menuAction());
        menuBar->addAction(actionInformacje->menuAction());
        actionInformacje->addAction(actionInformacje_2);
        menuPlik->addAction(actionWczytaj);
        menuPlik->addAction(actionZapisz_tabel);
        menuPlik->addAction(actionPolicz);
        menuPlik->addAction(actionWyj_cie);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionWyj_cie->setText(QApplication::translate("MainWindow", "Wyj\305\233cie", 0));
        actionWczytaj->setText(QApplication::translate("MainWindow", "Wczytaj", 0));
        actionPolicz->setText(QApplication::translate("MainWindow", "Policz", 0));
        actionInformacje_2->setText(QApplication::translate("MainWindow", "Informacje", 0));
        actionZapisz_tabel->setText(QApplication::translate("MainWindow", "Zapisz tabel\304\231", 0));
        pushButton->setText(QApplication::translate("MainWindow", "++ Wiersz", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "-- Wiersz", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "++ Kolumna", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "-- Kolumna", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "ARG", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "VAL", 0));
        actionInformacje->setTitle(QApplication::translate("MainWindow", "Informacje", 0));
        menuPlik->setTitle(QApplication::translate("MainWindow", "Plik", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
