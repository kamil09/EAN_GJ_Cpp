#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionWczytaj_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Wybierz plik"),"","(*.*)");
    int varCount=0;
    int rowCount=0;
    QString** values = NULL;
    values = readFile(filename, &varCount,&rowCount,values);

    if((varCount > 0) && (rowCount > 0) ){
        ui->tableWidget->setColumnCount(varCount);
        ui->tableWidget->setRowCount(rowCount);
        for(int i=0 ; i<rowCount; i++){
            for(int k=0; k<varCount; k++){
                 ui->tableWidget->setItem(i,k, new QTableWidgetItem(values[i][k]));
            }
        }
        checkCanMakeCalc();
    }
    else
        QMessageBox::information(this,tr("ERROR!!!"),tr("Oj, nie udało się wczytać pliku..."));
    return;
}

void MainWindow::on_actionWyj_cie_triggered()
{
  QApplication::quit();
}

void MainWindow::on_actionInformacje_2_triggered()
{
  QMessageBox::information(this,tr("Informacje"),tr(
                             "Rozwiazywanie układów równań liniowych medodą Gaussa-Jordana\n"
                             "Auton: Kamil Piotrowski\n"
                             "Program powstał na potrzeby przedmiotu Elementy Analizy Numerycznej"
                             ));
}

void MainWindow::on_actionPolicz_triggered()
{

}

void  MainWindow::checkCanMakeCalc(){
     if( ui->tableWidget->columnCount()>0 && ui->tableWidget->rowCount() > 0 )
        ui->actionPolicz->setEnabled(true);
     else
       ui->actionPolicz->setEnabled(false);
}

void MainWindow::on_pushButton_clicked()
{
     ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
     checkCanMakeCalc();
}

void MainWindow::on_pushButton_2_clicked()
{
   if(ui->tableWidget->rowCount() > 0)
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()-1);
   checkCanMakeCalc();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->tableWidget->setColumnCount(ui->tableWidget->columnCount()+1);
    checkCanMakeCalc();
}

void MainWindow::on_pushButton_4_clicked()
{
  if(ui->tableWidget->columnCount()>0)
    ui->tableWidget->setColumnCount(ui->tableWidget->columnCount()-1);
  checkCanMakeCalc();
}

void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
   bool dobre;
    ui->tableWidget->item(row,column)->text().toDouble(&dobre);
    if(!dobre){
          QMessageBox::information(this,tr("ERROR!!!"),tr("Nieprawidłowa wartość!"));
          ui->tableWidget->item(row,column)->setText("0");
      }
}

void MainWindow::on_actionZapisz_tabel_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("Wybierz plik do zapisu"),"","Text File (*.txt)");
    QFile file( filename );
    file.open(QIODevice::WriteOnly);
    if(!file.isOpen())
      return;
    QTextStream out(&file);
    out << ui->tableWidget->rowCount() << endl;
    out << ui->tableWidget->columnCount() << endl;
    for(int i=0 ; i<ui->tableWidget->rowCount(); i++){
        for(int k=0; k<ui->tableWidget->columnCount(); k++){
             out << ui->tableWidget->item(i,k)->text();
             out << " ";
        }
        out << endl;
    }

    file.close();
}
