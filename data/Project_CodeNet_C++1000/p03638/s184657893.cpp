#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef deque<ll> dqll;

const ll mod = 1000000007;

vector<ll> cst;
vector<vector<P>> lst;

int main() {
  ll H, W, N;
  cin >> H >> W >> N;

  vll lst(N);
  vll tmp(W);

  for (ll i = 0; i < N; i++) {
    cin >> lst[i];
  }

  ll use = 0;
  ll col = 0;
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      ll tmp_idx = (i % 2 == 0) ? j : W - 1 - j;
      tmp[tmp_idx] = col+1;
      use++;
      if (use >= lst[col]) {
        col += 1;
        use = 0;
      }
    }
    for (ll j = 0; j < W; j++) {
      cout << tmp[j] << " ";
    }
    cout << endl;
  }

  return 0;
}
