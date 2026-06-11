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
 
const int MAX = 1000;
 
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

void sosuu(ll n, vector<ll> &v){

  vector<ll> num(n, 0);

  FOR(i, 1, sqrt(n)){
    if(num[i]==0){
      FOR(j, 0, n/i){
        num[i+(j*i)] = 1;
      }
    }
  }
  REP(i, n){
    if(num[i]==0) v.push_back(i+1);
  }
}


int main(void){

    ll n;
  cin>>n;
  vector<ll> s(n);
  ll sum = 0;
  REP(i, n){
    ll x;
    cin>>x;
    s[i] = x;
    sum += x;
  }
  if(sum%10!=0) cout<<sum<<endl;
  else{
    ll sub;
    sort(s.begin(), s.end());
    ll sub_sum = s[0];
    ll count = 0;

    while(1){
      if(count>=n){
        cout<<"0"<<endl;
        return 0;
      }
      
      if(s[count]%10!=0){
        sub = min(sub_sum, s[count]);
        break;
      }else{
        sub_sum += s[count];
      }
      count++; 
    }
    cout<<sum-sub<<endl;
  }
  
  
  
}