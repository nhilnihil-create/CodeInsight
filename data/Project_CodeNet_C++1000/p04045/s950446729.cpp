#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#define ll long long int
#define hell 1000000007LL
using namespace std;
ll power(ll x, ll y){ 
    if(y==0)
     return 1;
    else
    {
        ll p=power(x,y/2);
        if(y%2==0)
         return (p*p)%hell;
        else
        return (x*((p*p)%hell))%hell;
    }}
ll gcd(ll x,ll y)
{
    if(y==0)
     return x;
    else
    return gcd(y,x%y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(20);
   ll x,n;
   cin>>x>>n;
   ll a[n];
   ll b[10]={0};
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
       b[a[i]]=1;
   }
   while(1)
   {
       ll y=x,f=0;
       while(y>0)
       {
           ll z=y%10;
           if(b[z]==1)
           f++;
           y=y/10;
       }
       if(f==0)
       {
           cout<<x;
           exit(0);
       }
       else
       ++x;
   }}
       
   