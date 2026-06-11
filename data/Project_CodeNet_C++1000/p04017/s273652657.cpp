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

const int N = 1e5 + 30;
const int B = 17;

int dp[N][B];

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) {
    cin >> i;
  }
  int L;
  cin >> L;
  a.push_back(a.back() + L);

  dp[n - 1][0] = n;
  dp[n][0] = n;
  for (int i = n - 2; i >= 0; i--) {
    dp[i][0] = dp[i + 1][0];
    while (a[dp[i][0]] - a[i] > L) {
      dp[i][0]--;
    }
  }

  for (int b = 1; b < B; b++) {
    for (int i = 0; i <= n; i++) {
      dp[i][b] = dp[dp[i][b - 1]][b - 1];

    }
  }

  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (a > b) {
      swap(a, b);
    }
    int ans = 0;
    
    for (int bit = B - 1; a < b && bit >= 0; bit--) {
      if (dp[a][bit] < b) {
        a = dp[a][bit];
        ans += (1 << bit);
      }
    }
    cout << ans + 1 << "\n";
  }
  return 0;
}