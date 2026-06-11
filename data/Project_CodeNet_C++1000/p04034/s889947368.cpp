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
  ll n,m; cin >>n>>m;
  vector<ll> x(m);
  vector<ll> y(m);
  vector<ll> have(n);
  rep(i,m) cin >>x[i]>>y[i];
  map<ll,ll> mp;
  rep(i,n)mp[i]=1;
  have[0]=1;
  rep(i,m){
    if(mp[x[i]-1]==1){
      if(have[x[i]-1]==1){
        have[x[i]-1]=0;
        have[y[i]-1]=1;
      }
    }else if(mp[x[i]-1]>1){
      if(have[x[i]-1]==1){
        have[y[i]-1]=1;
      }
    }
      mp[x[i]-1]--;
      mp[y[i]-1]++;
  }
  ll ans=0;
  rep(i,n)if(have[i]==1)ans++;
  cout <<ans<<endl;
}