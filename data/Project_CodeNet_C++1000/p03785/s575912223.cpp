
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
  ll n,c,k; cin>>n>>c>>k;
  vector<ll> t(n);
  rep(i,n) cin>> t[i];
  sort(all(t));
  ll ans=0;
  ll key=1;
  ll lowest=t[0];
  rep2(i,1,n){
    //cout <<ans<<key<<lowest<<endl;
    key++;
    if(i==n-1){
    if(lowest+k<t[i]){
      ans+=2;
      key=1;
      lowest=t[i];
      continue;
    }
    if(key-1==c){
      ans+=2;
      key=1;
      lowest=t[i];
      continue;
    }
      ans++;
    }else{
      if(lowest+k<t[i]){
      ans++;
      key=1;
      lowest=t[i];
      continue;
    }
    if(key-1==c){
      ans++;
      key=1;
      lowest=t[i];
      continue;
    }
    }
  }
  cout <<ans<<endl;
}