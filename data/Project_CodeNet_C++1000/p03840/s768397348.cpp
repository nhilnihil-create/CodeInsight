#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

#define rep(X, Y) for (int(X) = 0; (X) < (Y); ++(X))
#define rrep(X, Y) for (int(X) = (Y)-1; (X) >= 0; --(X))
#define all(X) (X).begin(), (X).end()
#define pb push_back
#define mp make_pair
#define fi first
#define sc second
#define print(x) cout << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

void solve(long long a_I, long long a_O, long long a_T, long long a_J,
           long long a_L, long long a_S, long long a_Z) {
  ll ans = 0;
  ans += (a_I / 2) * 2;
  ll a_I_rest = a_I % 2;

  ans += a_O;

  ans += (a_J / 2) * 2;
  ll a_J_rest = a_J % 2;

  ans += (a_L / 2) * 2;
  ll a_L_rest = a_L % 2;

  ll rest = a_I_rest + a_J_rest + a_L_rest;
  if (rest == 3) {
    ans += 3;
  } else if (rest == 2) {
    if (a_I_rest == 1) {
      if (a_J_rest == 1) {
        if (a_L > 0) {
          ans++;
        }
      } else {
        if (a_J > 0) {
          ans++;
        }
      }
    } else {
      if (a_I > 0) {
        ans++;
      }
    }
  }

  print(ans);
}

int main() {
  long long a_I;
  scanf("%lld", &a_I);
  long long a_O;
  scanf("%lld", &a_O);
  long long a_T;
  scanf("%lld", &a_T);
  long long a_J;
  scanf("%lld", &a_J);
  long long a_L;
  scanf("%lld", &a_L);
  long long a_S;
  scanf("%lld", &a_S);
  long long a_Z;
  scanf("%lld", &a_Z);
  solve(a_I, a_O, a_T, a_J, a_L, a_S, a_Z);
  return 0;
}
