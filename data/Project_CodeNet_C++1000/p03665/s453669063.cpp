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
 
  COMinit();
 
  ll n, p;
  cin>>n>>p;
  ll gu = 0;
  ll ki = 0;
 
  REP(i, n){
    ll x;
    cin>>x;
    if(x%2==0) gu++;
    else ki++; 
  }
 
  ll ans = 0;
 
  if(p==0){
    ll gu_num = 0;
    ll ki_num = 0;
    ll count = 1;
    while(1){
      if(gu < count) break;
      gu_num += COM(gu, count);
      count++;
    }
    count = 1;
    while(1){
      if(ki < count*2) break;
      ki_num += COM(ki, count*2);
      //cout<<ki<<count*2<<endl;;
      count++;
    }
    //cout<<gu_num<<" "<<ki_num<<endl;
    ans = (gu_num+1) * (ki_num+1);
 
  }else{
    ll gu_num = 0;
    ll ki_num = 0;
    ll count = 1;
    while(1){
      if(gu < count) break;
      gu_num += COM(gu, count);
      count++;
    }
    count = 1;
    while(1){
      if(ki < count) break;
      ki_num += COM(ki, count);
      count+=2;
    }
    ans = (gu_num+1) * (ki_num);
  }
 
  cout<<ans<<endl;
  return 0;
 
}