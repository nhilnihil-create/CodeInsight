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

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;

int main() {
  string str;
  cin >> str;
  ll nn = (ll)str.size();

  ll cnt = 0;
  for (size_t i = 0; i < str.size(); i++) {
    if (str[i] == 'p') cnt++;
  }

  cout << nn/2 - cnt << endl;

  return 0;
}