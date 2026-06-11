#include<bits/stdc++.h>
using namespace std ;
int main ()
{
  int  a,b,c,m,n,x;
  cin>>a>>b>>c;
  m=a+b;
  n= a+c;
  x= b+c ;
 if (m<=n && m<=x)
  cout<<m<<endl;
 else if (n<=m && n<=x)
 cout<<n<<endl;
 else
 cout<<x<<endl;
return 0;
}