//by The_One_Solver
#include<bits/stdc++.h>
using namespace std;
long long v,o,p,n,m,c,h,a,b,d;
int main()
{
  cin>>a>>b>>c;
  if(a%2||b%2||c%2)return cout<<0,0;
  while(m<10000)
  {    n=a,d=b,h=c;
      a=(d/2)+(h/2);
      b=(n/2)+(h/2);
      c=(d/2)+(n/2);
      m++;
      if(a%2==1||b%2==1||c%2==1)break;

  }
  if(m<10000)
  cout<<m;
  else cout<<-1;
    return 0;
}
