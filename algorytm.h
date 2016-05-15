#ifndef ALGORYTM_H
#define ALGORYTM_H

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <QString>
#include <QTextStream>
#include "Interval.h"

void returnRow(int i, int n, long double* a, long double **input);
void returnRowInterval(int i, int n, interval_arithmetic::Interval<long double>* a, char ***);
long double *GaussJordan(int n,long  double result[], int *st,long  double **input);
void GaussJordanInterval (int n, interval_arithmetic::Interval<long double> *resultInterval , int *status, char ***numbersChar);

#endif // ALGORYTM_H
