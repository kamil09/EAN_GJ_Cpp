#ifndef ALGORYTM_H
#define ALGORYTM_H

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <QString>
#include <QTextStream>
#include "Interval.h"

void returnRow(int i, int n, double* a, double **input);
void returnRowInterval(int i, int n, interval_arithmetic::Interval<double>* a, char ***);
double *GaussJordan(int n, double result[], int *st, double **input);
void GaussJordanInterval (int n, interval_arithmetic::Interval<double> *resultInterval , int *status, char ***numbersChar);

#endif // ALGORYTM_H
