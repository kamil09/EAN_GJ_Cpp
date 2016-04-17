#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <stdio.h>
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>
#include "plik.h"
#include <QString>
#include "algorytm.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

private slots:
     void checkCanMakeCalc();

    void on_actionWczytaj_triggered();

    void on_actionWyj_cie_triggered();

    void on_actionInformacje_2_triggered();

    void on_actionPolicz_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableWidget_cellChanged(int row, int column);

    void on_actionZapisz_tabel_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
