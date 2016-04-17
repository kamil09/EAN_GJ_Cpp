#include "algorytm.h"

double *oneeqn(int i, int n, double* a, double **input){
//    for(int k=1;k<=n;k++){
//      a[k]=input[i-1][k-1];
//     }
  switch (i){
     case  1 :
            a[1]=3;  a[2]=1;  a[3]=6;  a[4]=2;
          break;
      case 2 :
            a[1]=2;  a[2]=1;  a[3]=3;  a[4]=7;
          break;
      case 3 :
            a[1]=1;  a[2]=1;  a[3]=1;  a[4]=4;
          break;
    }
  return a;
}

double *GaussJordan (int n, double *result, int *st, double **input)
{
   int i,j,jh,k,kh,l,lh,n1,p,q,rh;
   double max,s;
   double *a,b[n+2];
   a=new double[n+2];
   double r[n+2];

   *st=0;
   if ( n<1 ) *st=1;

   if ( *st==0 ) {
      n1=n+1;
      p=n1;
      for (i=1 ; i<=n1 ; i++ )  r[i]=0;
      k=0;
      do{
         k=k+1;
         a = oneeqn (k,n1,a,input);
         for ( i=1 ; i <= n ; i++){
            rh=r[i];
            if ( rh!=0 ) b[rh]=a[i];
         }
         kh=k-1;
         l=0;
         max=0;
         for ( j=1 ; j <= n1 ; j++ )
            if ( r[j] == 0){
               s=a[j];
               l=l+1;
               q=l;
               for ( i=1 ; i <= kh ; i++ ){
                  s=s-b[i]*result[q];
                  q=q+p;
               }
               a[l]=s;
               s=abs(s);
               if ( (j<n1) && (s>max)){
                  max=s;
                  jh=j;
                  lh=l;
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
               for (i=1 ; i <= p ; i++)
                  if (i!=lh){
                     jh=jh+1;
                     result[jh]=result[q+i]-s*a[i];
                  }
               q=q+p;
            }
            for (i=1 ; i<= p ; i++)
               if ( i != lh ){
                  jh=jh+1;
                  result[jh]=a[i];
               }
            p=p-1;
         }
      } while( (k!=n) && (*st!=2) );

      if (st==0)
         for (k=1; k<= n ; k++){
            rh=r[k];
            if (rh!=k){
               s=result[k];
               result[k]=result[rh];
               i=r[rh];
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
   return result;
}
