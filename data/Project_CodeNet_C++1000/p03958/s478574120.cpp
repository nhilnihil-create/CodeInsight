#include <bits/stdc++.h>
#include <limits>
#include <math.h>
#include <cmath>
#include <cctype>
#include <cstdio>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int> ;
using vll = vector<long long>;
using vvll = vector<vector<long long >>;
#define PI 3.141592653
#define rep(i, n) for(ll i = 0; i < n; i++)


int main(){
  ll n, m;
  cin >> n >> m;
  vll v(m);
  rep(i, m){
    cin >> v[i];
  }
  sort(v.begin(), v.end());

  ll sum = 0;
  rep(i, m-1){
    sum += v[i];
  }

  
  if(sum >= v[m-1]){cout << 0 << endl;}
  else{cout << v[m-1]-sum-1 << endl;}
}
