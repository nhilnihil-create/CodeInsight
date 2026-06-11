#include <iostream>
#include<cmath> 
using namespace std ;
int main()
{ 
long long R=0;
long long t,i,N,M;
cin>>N;
M=N-1;
  long long*a= new long long[N];
  long long*b= new long long[M];
  for(i=0;i<N;i++)
   {
   cin>>a[i];
    R+=a[i];
   }
    b[0]=a[0];
    for(i=1;i<N-1;i++)
    b[i]=b[i-1]+a[i];
    for(i=0;i<N-1;i++)
    if(abs(R-2*b[i])<t||i==0)
      t=abs(R-2*b[i]);
cout<<t;
delete[] a;
delete [] b;
return 0;
}