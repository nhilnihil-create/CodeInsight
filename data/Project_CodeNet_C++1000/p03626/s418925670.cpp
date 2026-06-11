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

int main() {
  ll N;
  cin >> N;

  string str;
  cin >> str;
  ll cur = 0;
  ll ans = 1;
  ll state = 0;
  while (cur < N) {
    if (cur == 0) {
      if (cur == N - 1 || str[cur] != str[cur + 1]) {
        ans *= 3;
        ans %= mod;
        cur++;
        state = 0;
      } else {
        ans *= 6;
        ans %= mod;
        cur += 2;
        state = 1;
      }
    } else {
      if (cur == N - 1 || str[cur] != str[cur + 1]) {
        if (state == 0) {
          ans *= 2;
        } else {
          // do nothing
        }
        ans %= mod;
        cur++;
        state = 0;
      } else {
        if (state == 0) {
          ans *= 2;
        } else {
          ans *= 3;
        }
        ans %= mod;
        cur += 2;
        state = 1;
      }
    }
  }  // while

  cout << ans << endl;

  return 0;
}