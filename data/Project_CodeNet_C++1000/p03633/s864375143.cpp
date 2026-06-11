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
int main(){
  ll n; cin >>n;
  vector<ll> t(n);
  rep(i,n) cin >> t[i];
  ll ans=t[0];
  rep(i,n-1){
    ans = ans/__gcd(ans,t[i+1])*t[i+1];
  }
  cout <<ans<<endl;
}