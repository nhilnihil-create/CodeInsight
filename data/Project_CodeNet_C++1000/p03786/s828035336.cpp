#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include<vector>
#include<iomanip>
#include<map>
#include <queue>
#include<cmath>
#include<cstdio>
#include<iomanip>
#include<set>
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long int;
 
#define REP(i,n) for(ll i=0;i<(ll)(n);i++) //REP(i, 5) cout<<i;
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define MOD 1000000007 //10^9+7
//#define MOD 1
 
ll gcd(ll a, ll b) {
  ll tmp;
  if ( b > a) {
    tmp = a;
    a = b;
    b = tmp;
  }
  while (a % b !=0) {
    tmp = b;
    b = a % b;
    a = tmp;
  }
  return b;
}
 
const int MAX = 50;
 
ll table[MAX][MAX];
 
// テーブルを作る前処理
void COMinit() {
    table[0][0] = table[0][1] = 1;
    FOR(i, 1, MAX-1){
      FOR(j, 0, i+1){
        if(j==0) table[i][j] = 1;
        else if(j == i+1) table[i][j] = 1;
        else table[i][j] = table[i-1][j-1]+table[i-1][j];
      }
    }
}
 
// 二項係数計算
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return table[n-1][k];
}


int main(void){
 
  ll n;
  cin>>n;

  vector<ll> a(n);
  REP(i, n){
    ll x;
    cin>>x;
    a[i] = x;
  }
  sort(a.begin(), a.end());

  vector<ll> sum(n);
  sum[0] = a[0];
  FOR(i, 1, n-1) sum[i] = sum[i-1] + a[i];

  ll ans = 1;
  for(int i=n-2;i>=0;i--){
    if(a[i]*2>=a[n-1]) ans++;
    else{
      if(sum[i]*2>=a[i+1]) ans++;
      else i = -1;
    }
  }

  cout<<ans<<endl;
  return 0;
}