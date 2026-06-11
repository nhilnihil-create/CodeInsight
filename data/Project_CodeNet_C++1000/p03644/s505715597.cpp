#include <iostream>
#include <bits/c++io.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
int n,maxs=0,t=0,m,c,j=0,z=0;
cin>>n;
m=c=n;
for(int i=0;i<c;i++)
{
    j++;
      while(n%2==0)
   {
       t++;
       n/=2;
   }

   if(t>maxs)
    {
        maxs=t;

    }
n=m;
   n-=j;
   t=0;
}
cout<<pow(2.0,maxs)<<endl;
}
