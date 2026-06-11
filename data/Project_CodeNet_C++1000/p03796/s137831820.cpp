#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#define ll long long
#define lli long long int

using namespace std;
using P = pair<int,int>;

int main(){

  ll N;
  ll mod = 1e9+7;
  ll p = 1;
  ll ans = 0;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    p = i*p%mod;
  }

  cout << p << endl;

  return 0;
}