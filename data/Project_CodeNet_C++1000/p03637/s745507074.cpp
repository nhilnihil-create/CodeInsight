#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define _GLIBCXX_DEBUG
#define ll long long
#define rep(i,n) for (ll i = 0; i < n; i++)
#define vl vector<ll>
#define vpl vector<pair<ll,ll>>
#define vvl vector<vector<ll>> //a(縦行,vector<ll>(横列));
#include<algorithm>//__gcd(a,b)
#include <iostream>
#include <vector>
#include <cstdlib>
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;

int main(){
   ll n;cin>>n;
   vl a(n);rep(i,n)cin>>a[i];
   ll tw=0;ll fo=0;

   rep(i,n){
       if(a[i]%2==0&&a[i]%4!=0)tw++;
       if(a[i]%4==0)fo++;
   }

   if(tw<2)tw=0;//二個以上ないと使えない
   if(tw>=2)tw--;
   

if(n-1-tw-2*fo>0)cout<<"No"<<endl;
else{cout<<"Yes"<<endl;}
}