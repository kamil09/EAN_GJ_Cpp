#ifndef ALGORYTM_H
#define ALGORYTM_H

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <QString>
#include <QTextStream>

void returnRow(int i, int n,long  double* a, long double **input);
long double *GaussJordan(int n, long double result[], int *st,long double **input);

#endif // ALGORYTM_H
