#include "algorytm.h"
#include "Interval.h"


void returnRow(int i, int n, long double* a, long double **input){
   for(int k=1;k<=n;k++) a[k]=input[i-1][k-1];
}

void returnRowInterval(int i, int n, interval_arithmetic::Interval<long double>* a, string **input){
   for(int k=1;k<=n;k++){
      interval_arithmetic::Interval<long double>* r = new interval_arithmetic::Interval<long double>(
         interval_arithmetic::Interval<long double>::LeftRead(input[i-1][k-1]),
         interval_arithmetic::Interval<long double>::RightRead(input[i-1][k-1])
      );
      a[k]=*r;
   }
}

/**
n : liczba wierszy ; n+1 - liczba kolumn
result: tablica z wynikiem
status: status algorytmu
input: maciez wejściowa
*/
void GaussJordan (int n,  long double result[], int *status,  long  double **input){
   int j,jh=0,k=0,lh=0,p,q,rh;
   long  double max,s;
   long  double a[n+2],b[n+2];
   int r[n+2];

   *status=0;
   if (n<1) *status=1;           //Gdy nie ma danych :(

   if ( *status==0 ) {
      p=n+1;
      for (int i=0 ; i<=n+1 ; i++ )  r[i]=0;

      do{
        k++;
        returnRow (k,n+1,a,input);
        for (int i=1 ; i <= n ; i++)
            if ( r[i]!=0 ) b[r[i]]=a[i];

         int l=0;
         max=0;
         for (j=1 ; j <= n+1 ; j++ ){
            if ( r[j] == 0){
               s=a[j];
               l++;
               q=l;
               for (int i=1 ; i <= k-1 ; i++ ){
                  s=s-b[i]*result[q];
                  q=q+p;
               }
               a[l]=s;
               s=fabs(s);
               if ( (j<n+1) && (s>max)){
                  max=s;
                  jh=j;
                  lh=l;
               }
            }
         }
         if (max==0) {
            *status=2;              //Jeśli maksymalny c do wart. bezw. jest 0 to nie można dalej liczyć - maciez jest osobliwa!
            return;
         }
         else {
            max=1/a[lh];
            r[jh]=k;
            for (int i=1 ; i <= p ; i++)
               a[i]=max*a[i];             //Dzielimy wiersz przez MAX
            jh=0;
            q=0;
            for (j=1 ; j <= k-1 ; j++){
               s=result[q+lh];
               for (int i=1 ; i <= p ; i++){
                  if (i!=lh){
                     jh=jh+1;
                     result[jh]=result[q+i]-s*a[i];
                  }
               }
               q+=p;
            }
            for (int i=1 ; i<= p ; i++){
               if ( i != lh ){
                  jh=jh+1;
                  result[jh]=a[i];
               }
            }
            p--;
         }
      } while((k!=n) && (*status != 2) );

      if ( (*status) == 0){               //Przywrócenie odpowiedzniej kolejności zmiennych
         for (k=1; k<= n ; k++){
            rh=r[k];
            if (rh!=k){
               s=result[k];
               result[k]=result[rh];
               int  i=r[rh];
               while( i != k){
                 result[rh]=result[i];
                 r[rh]=rh;
                 rh=i;
                 i=r[rh];
               }
               result[rh]=s;
               r[rh]=rh;
            }
         }
      }
   }

   return;
}

/**
 * Algorytm z pełnym wyborem pozwala osiągnąć największą dokładność, ponieważ dzielimy współczynniki najpierw przez MAX,
 * co za tym idzie następne operacje są wykonywane na liczbach z przedziału <0;1>. Jest to optymalniejsze od wykonywania operacji
 * na większych liczbach ponieważ bliżej 0 liczby maszynowe są gęściej upakowane. (mamy więc większą dokładnośc)
 */
void GaussJordanInterval (int n, interval_arithmetic::Interval<long double> *resultInterval , int *status, string **numbersChar)
{
   int j,jh=0,k=0,l,lh=0,p,q,rh;
   interval_arithmetic::Interval<long double> max,s;
   interval_arithmetic::Interval<long double> a[n+2],b[n+2];
   int r[n+2];
   ostringstream ss;

   *status=0;
   if (n<1) *status=1;

   if ( *status==0 ) {
      p=n+1;
      for (int i=1 ; i<=n+1 ; i++ )  r[i]=0;

      do{
        k++;
        returnRowInterval (k,n+1,a,numbersChar);
        for (int i=1 ; i <= n ; i++)
            if ( r[i]!=0 ) b[r[i]]=a[i];

         l=0;
         max=interval_arithmetic::Interval<long double>::IntRead("0");
         for (j=1 ; j <= n+1 ; j++ ){
            if ( r[j] == 0){
               s=a[j];
               l++;
               q=l;
               for (int i=1 ; i <= k-1 ; i++ ){
                  s=s-b[i]*resultInterval[q];
                  q=q+p;
               }
               a[l]=s;
               s=s.Abs();
               if ( (j<n+1) && ( s.a>=max.a && s.b>=max.b )){
                  max=s;
                  jh=j;
                  lh=l;
               }
            }
         }
         if (max.a <=0 && max.b>=0 ){
             *status=2;
             return;
          }
         else {
           max=a[lh].Inverse();
           r[jh]=k;
            for (int i=1 ; i <= p ; i++)
               a[i]=max*a[i];
            jh=0;
            q=0;
            for (j=1 ; j <= k-1 ; j++){
               s=resultInterval[q+lh];
               for (int i=1 ; i <= p ; i++){
                  if (i!=lh){
                     jh=jh+1;
                     resultInterval[jh]=resultInterval[q+i]-s*a[i];
                  }
               }
               q+=p;
            }
            for (int i=1 ; i<= p ; i++){
               if ( i != lh ){
                  jh=jh+1;
                  resultInterval[jh]=a[i];
               }
            }
            p--;
         }
      } while((k!=n) && ( (*status) != 2) );

      if ( (*status) == 0){
         for (k=1; k<= n ; k++){
            rh=r[k];
            if (rh!=k){
               s=resultInterval[k];
               resultInterval[k]=resultInterval[rh];
               int  i=r[rh];
               while( i != k){
                 resultInterval[rh]=resultInterval[i];
                 r[rh]=rh;
                 rh=i;
                 i=r[rh];
               }
               resultInterval[rh]=s;
               r[rh]=rh;
            }
         }
      }
  }
}
