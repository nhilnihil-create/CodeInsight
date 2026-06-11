#define _GLIBCXX_DEBUG
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<string>
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define rep2(i,s,n) for(int i=s;i< (int)n; i++)
#define ll long long 
#define all(v) v.begin(),v.end()
using namespace std;
const ll inf = 1000000007;
int main() {
  ll n,m ; cin >>n>>m;
  ll np=1;
  ll mp=1;
  rep(i,n){
    np*=i+1;
    np=np%inf;
  }
  rep(i,m){
    mp*=i+1;
    mp=mp%inf;
  }
  ll ans=(np*mp)%inf;
  if(n==m+1||n==m-1)cout <<ans<<endl;
  else if(n==m)cout  <<(ans*2)%inf<<endl;
  else cout <<0<<endl;
}