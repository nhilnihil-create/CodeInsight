#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
const int N =1e4+5;
int n,k,x,y;
int main(){
     scanf("%d %d %d %d",&n,&k,&x,&y);
     ll ans=0;
     for(ll i=0;i<n;i++)
     {
          if(k>0)
          {
               ans+=x;
               k-=1;
          }
          else 
               ans+=y;     
     }
     printf("%lld\n",ans);
}
