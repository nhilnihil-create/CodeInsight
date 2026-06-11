/*
❤️❤️❤️I_love_QMsh❤️❤️❤️
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define x first
#define y second

using namespace std;
using namespace __gnu_pbds; // gp_hash_table<int, int> table;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; // <int> .find_by_order(int) .order_of_key(int)

template<typename T> bool smin(T &a, const T &b) { bool ret = b < a; return a = (ret ? b : a), ret; }
template<typename T> bool smax(T &a, const T &b) { bool ret = a < b; return a = (ret ? b : a), ret; }

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

mt19937 rnd;

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  ll ans = 0;
  for (int mask = 0; mask < (1 << (n - 1)); mask++) {
    ll cur = 0;
    for (int b = 0; b < n; b++) {
      cur = (cur * 10 + s[b] - '0');
      if (mask >> b & 1) {
        ans += cur;
        cur = 0;
      }
    }
    ans += cur;
  }
  cout << ans;
  return 0;
}