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
#define itrep(X, Y) for (auto(X) = (Y).begin(); (X) != (Y).end(); (X)++)
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

void solve(long long X, long long Y) {
  if (abs(X - Y) <= 1) {
    print("Brown");
  } else {
    print("Alice");
  }
}

int main() {
  long long X;
  scanf("%lld", &X);
  long long Y;
  scanf("%lld", &Y);
  solve(X, Y);
  return 0;
}
