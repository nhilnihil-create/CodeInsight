//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>
#include <deque>
#include <set>
#include <stack>

using namespace std;

typedef long long ll;
const ll nmax = 1e9 + 7;
const ll mod = 998244353;
const long long INF = 1e18;
const double PI = 2 * asin(1);

ll gcd (ll A, ll B){
  ll M = max(A, B), m = min(A, B);
  while (M % m != 0){
    ll c = M % m;
    M = m; m = c;
  }
  return m;
}

int main(){
  ll N, X; cin >> N >> X;

  cout << 3 * (N - gcd(N, X)) << endl;
  return 0;
}
