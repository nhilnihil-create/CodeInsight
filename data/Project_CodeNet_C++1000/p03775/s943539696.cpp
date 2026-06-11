#include <stdio.h>
#include <math.h>
#include<bits/stdc++.h>
using namespace std;
#define int long long int

int i,j,k,m;
main()
{
  int n;
  cin>>n;
  int m=0;
  for(i=sqrt(n);i>=2;i--)
  {
      if(n%i==0) {m=i;break;}
  }
  if(!m)
  {
      int t=0;
      while(n>0)
      {
          n=n/10;
          t++;
      }
      cout<<t<<endl;
  }
  else
  {
      int k=n/m;
       int t=0,t1=0;
      while(m>0)
      {
          m=m/10;
          t++;
      }

      // int t=0;
      while(k>0)
      {
          k=k/10;
          t1++;
      }
      cout<<max(t,t1)<<endl;
  }
}

