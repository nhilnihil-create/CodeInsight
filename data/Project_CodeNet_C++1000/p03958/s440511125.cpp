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
//#define MOD 1000000007 //10^9+7
#define MOD 2019

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

int main(void){

  ll k, t;
  cin>>k>>t;
  vector<ll> a(t);
  ll max = 0;
  REP(i, t){
    ll x;
    cin>>x;
    a[i] = x;
    if(max < x) max = x;
  }

  if(k%2==0 && max < k/2){
    cout<<"0"<<endl;
  }else if(k%2==1 && max < (k/2 +1)){
    cout<<"0"<<endl;
  }else{
    cout<<max - (k- max) -1<<endl;
  }
  
  return 0;

}