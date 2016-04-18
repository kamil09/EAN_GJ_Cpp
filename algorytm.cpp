#include "algorytm.h"

void returnRow(int i, int n, long double* a, long double **input){
   for(int k=1;k<=n;k++){
      a[k]=input[i-1][k-1];
   }
}

long double *GaussJordan (int n,long  double result[], int *st, long double **input)
{
   int i,j,jh=0,k,kh=0,l,lh=0,n1,p,q,rh;
   long double max,s;
   long double a[n+2],b[n+2];
   long double r[n+2];

   for (int ppp=1; ppp<=n; ppp++) std::cout <<result[ppp] << " / "; std::cout << std::endl;

   *st=0;
   if ( n < 1 ) *st=1;

   if ( *st==0 ) {
      n1=n+1;
      p=n1;
      for (i=1 ; i<=n1 ; i++ )  r[i]=0;
      k=0;
      do{
        k=k+1;
        returnRow (k,n1,a,input);
         for ( i=1 ; i <= n ; i++){
            rh=r[i];
            if ( rh!=0 ) b[rh]=a[i];
         }
         kh=k-1;
         l=0;
         max=0;
         for ( j=1 ; j <= n1 ; j++ ){
            if ( r[j] == 0){
               s=a[j];
               l=l+1;
               q=l;
               for ( i=1 ; i <= kh ; i++ ){
                  s=s-b[i]*result[q];
                  q=q+p;
               }
               a[l]=s;
               s=fabs(s);
               if ( (j<n1) && (s>max)){
                  max=s;
                  jh=j;
                  lh=l;
               }
            }
         }
         if (max==0) *st=2;
         else {
            max=1/a[lh];
            r[jh]=k;
            for (i=1 ; i <= p ; i++)
               a[i]=max*a[i];
            jh=0;
            q=0;
            for (j=1 ; j <= kh ; j++){
               s=result[q+lh];
               for (i=1 ; i <= p ; i++){
                  if (i!=lh){
                     jh=jh+1;
                     result[jh]=result[q+i]-s*a[i];
                      for (int ppp=1; ppp<=n; ppp++) std::cout <<result[ppp] << " / "; std::cout << std::endl;
                  }
               }
               q=q+p;
            }
            for (i=1 ; i<= p ; i++){
               if ( i != lh ){
                  jh=jh+1;
                  result[jh]=a[i];
                   for (int ppp=1; ppp<=n; ppp++) std::cout <<result[ppp] << " / "; std::cout << std::endl;
               }
            }
            p=p-1;
         }
      } while( !((k==n) || (*st == 2)) );

      if (*st==0){
         for (k=1; k<= n ; k++){
            rh=r[k];
            if (rh!=k){
               s=result[k];
               result[k]=result[rh];
                for (int ppp=1; ppp<=n; ppp++) std::cout <<result[ppp] << " / "; std::cout << std::endl;
               i=r[rh];
               while( i != k){
                 result[rh]=result[i];
                  for (int ppp=1; ppp<=n; ppp++) std::cout <<result[ppp] << " / "; std::cout << std::endl;
                 r[rh]=rh;
                 rh=i;
                 i=r[rh];
               }
               result[rh]=s;
                for (int ppp=1; ppp<=n; ppp++) std::cout <<result[ppp] << " / "; std::cout << std::endl;
               r[rh]=rh;
            }
         }
      }
   }


   return result;
}
