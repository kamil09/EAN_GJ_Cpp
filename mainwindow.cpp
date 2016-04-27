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

    QString filename = QFileDialog::getOpenFileName(this,tr("Wybierz plik"),"../EAN_GJ/","(*.*)");
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
   if(ui->tableWidget->columnCount()-1 != ui->tableWidget->rowCount() )
      QMessageBox::information(this,tr("ERROR!!!"),tr("Liczba kolumn musi wynosić liczbę wierszy +1!"));
   else{
     int st=0,st2=0;
     int n = ui->tableWidget->columnCount()-1;
     long double *result = new long double[n+2];
     interval_arithmetic::Interval<double> *resultInterval = new interval_arithmetic::Interval<double>[n+2];
     for(int i=0;i<=n+1;i++){
         result[i]=0;
         resultInterval[i]=interval_arithmetic::Interval<double>(0,0);
     }

     long double **numbers = new long double*[ui->tableWidget->rowCount()+1];
     for (int i=0;i<=ui->tableWidget->rowCount();i++)
     numbers[i] = new long double[ ui->tableWidget->columnCount()+1];
     char ***numbersChar = new char **[n+2];
     for(int i=0; i<=n+1;i++) numbersChar[i] = new char *[n+1];

     for(int i=0; i< ui->tableWidget->rowCount(); i++)
        for (int k=0; k< ui->tableWidget->columnCount(); k++){
          if(ui->tableWidget->item(i,k)){
            numbers[i][k]=ui->tableWidget->item(i,k)->text().toDouble();
            numbersChar[i][k]=ui->tableWidget->item(i,k)->text().toLatin1().data();
            }
          else{
              numbers[i][k]=0;
              numbersChar[i][k]="0";
            }
          }

    GaussJordan(n,result,&st, numbers);
    GaussJordanInterval(n,resultInterval,&st2,numbersChar);
    ui->tableWidget_2->setRowCount(3*n+1);

     for(int i=1;i<=n;i++){
         std::stringstream str;
         str << std::setprecision (16) << std::scientific << result[i];
          ui->tableWidget_2->setItem(i-1,0, new QTableWidgetItem("X["+QString::number(i)+"]"));
          ui->tableWidget_2->setItem(i-1,1, new QTableWidgetItem(QString::fromStdString(str.str())));
      }
      ui->tableWidget_2->setItem(n,1, new QTableWidgetItem("Arytmetyka przedziałowa:"));

     for (int i=0;i<=ui->tableWidget->rowCount();i++)
        delete numbers[i];
     delete numbers;
     delete result;


    }
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
