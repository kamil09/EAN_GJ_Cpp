#include "algorytm.h"
#include "Interval.h"


void returnRow(int i, int n, long double* a, long double **input){
   for(int k=1;k<=n;k++)
      a[k]=input[i-1][k-1];
}

void returnRowInterval(int i, int n, interval_arithmetic::Interval<long double>* a, string **input){
   for(int k=1;k<=n;k++){
       a[k]=interval_arithmetic::Interval<long double>::IntRead(input[i-1][k-1]);
   }
}

/**
n : liczba wierszy ; n+1 - liczba kolumn
result: tablica z wynikiem
status: status algorytmu
input: maciez wejściowa
*/
long double *GaussJordan (int n,  long double result[], int *status,  long  double **input){
   int j,jh=0,k=0,l,lh=0,p,q,rh;
   long  double max,s;
   long  double a[n+2],b[n+2];
   long  double r[n+2];

   *status=0;
   if (n<1) *status=1;

   if ( *status==0 ) {
      p=n+1;
      for (int i=0 ; i<=n+1 ; i++ )  r[i]=0;

      do{
        k++;
        returnRow (k,n+1,a,input);
         for (int i=1 ; i <= n ; i++)
            if ( r[i]!=0 ) b[(int)r[i]]=a[i];

         l=0;
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
         if (max==0) *status=2;
         else {
            max=1/a[lh];
            r[jh]=k;
            for (int i=1 ; i <= p ; i++)
               a[i]=max*a[i];
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

      if (*status==0){
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

   return result;
}


void GaussJordanInterval (int n, interval_arithmetic::Interval<long double> *resultInterval , int *status, string **numbersChar)
{
   int i,j,jh=0,k=0,l,lh=0,p,q,rh;
   interval_arithmetic::Interval<long double> max,s;
   interval_arithmetic::Interval<long double> a[n+2],b[n+2];
   interval_arithmetic::Interval<long double> r[n+2];
   ostringstream ss;


   *status=0;
   if (n<1) *status=1;

   if ( *status==0 ) {
      p=n+1;
      for (i=1 ; i<=n+1 ; i++ )  r[i].Initialize();

      do{
        k++;
        returnRowInterval (k,n+1,a,numbersChar);
         for (i=1 ; i <= n ; i++){
           long  double ax = r[i].a;
            long double bx = r[i].b;
             if ( !(ax<=0 && bx>=0 ) )
               b[(int)ax]=a[i];
           }

         l=0;
         max.Initialize();
         for (j=1 ; j <= n+1 ; j++ ){
            if ( r[j].a <=0 && r[j].b>=0){
               s=a[j];
               l++;
               q=l;
               for (i=1 ; i <= k-1 ; i++ ){
                  s=s-b[i]*resultInterval[q];
                  q=q+p;
               }
               a[l]=s;
               //s=fabs(s);
               if(s.a<=0 && s.b<=0 ){
                   long double tmp = s.b;
                   s.b=s.a*-1;
                   s.a=tmp*-1;
                 }
               else if(s.a <=0) s.a=0;

               if ( (j<n+1) && ( s.a>=max.a && s.b>max.b )){
                  max=s;
                  jh=j;
                  lh=l;
               }
            }
         }

         if (max.a <=0 && max.b>=0 ) *status=2;
         else {
           max=interval_arithmetic::Interval<long double>::IntRead("1")/a[lh];
           ss << k;
            r[jh]=interval_arithmetic::Interval<long double>::IntRead(ss.str());
            for (i=1 ; i <= p ; i++)
               a[i]=max*a[i];
            jh=0;
            q=0;
            for (j=1 ; j <= k-1 ; j++){
               s=resultInterval[q+lh];
               for (i=1 ; i <= p ; i++){
                  if (i!=lh){
                     jh=jh+1;
                     resultInterval[jh]=resultInterval[q+i]-s*a[i];
                  }
               }
               q+=p;
            }
            for (i=1 ; i<= p ; i++){
               if ( i != lh ){
                  jh=jh+1;
                  resultInterval[jh]=a[i];
               }
            }
            p--;
         }
      } while((k!=n) && (*status != 2) );


//      if (*status==0){
//         for (k=1; k<= n ; k++){
//            rh=r[k].a;
//            if (rh!=k){
//               s=resultInterval[k];
//               resultInterval[k]=resultInterval[rh];
//               i=r[rh].a;
//               while( i != k){
//                 resultInterval[rh]=resultInterval[i];
//                 r[rh].a=rh;
//                 r[rh].b=rh;
//                 rh=i;
//                 i=r[rh].a;
//               }
//               resultInterval[rh]=s;
//               r[rh].a=rh;
//               r[rh].b=rh;
//            }
//         }
//      }

  }
}
