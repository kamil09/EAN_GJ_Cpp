#ifndef PLIK_H
#define PLIK_H

#include <stdio.h>
#include <iostream>
#include <QTextStream>
#include <QFile>
#include <QTextStream>


QString** readFile(QString filename, int* varCount, int* rowCount,QString **tab);

#endif // PLIK_H
