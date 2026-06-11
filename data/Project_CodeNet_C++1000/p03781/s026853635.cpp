#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll bc(ll i)
{
    if(i==0)
    return 1;
    ll st=1;
    for(ll j=1;j<=i;j++)
    st*=2;
    return st;
}
void solve()
{
   
      ll n;
      cin>>n;
      double x=-1+sqrt(1+8*n);
      x/=2;
      ll y=(int)x;
      if(y==x)
       cout<<y<<endl;
       else
       cout<<y+1<<endl;
      
}
int main()
{
  ll t;
  //cin>>t;
  t=1;
  while(t--)
  {
      solve();
  }
   
   
   
}