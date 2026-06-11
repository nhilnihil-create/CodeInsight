// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
#include<bitset>
#include<cstdlib>
// #include<deque>
// #include<multiset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

int n;
int a[112345];
ll cnt[112345];

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  cin >> n;
  vector<pair<int, int>> v;
  for(int i = 1; i <= n; i++) cin >> a[i], v.emplace_back(a[i], i);
  sort(rbegin(v), rend(v));

  int mi = n;
  for(int i = 0; i < n; i++) {
    mi = min(mi, v[i].second);
    ll c = v[i].first - (i + 1 < n ? v[i+1].first : 0);
    cnt[mi] += c * (i + 1);
  }

  for(int i = 1; i <= n; i++) cout << cnt[i] << "\n";

  return 0;
}
