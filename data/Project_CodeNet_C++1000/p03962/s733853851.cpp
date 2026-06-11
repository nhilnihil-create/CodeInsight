#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
 int a,b,c;
 cin>>a>>b>>c;
 if(a==b && a==c)
  cout<<"1";
 else if((a==b && b!=c) || (b==c && b!=a) || (a==c && a!=b))
  cout<<"2";
 else
  cout<<"3";
 return 0;
}