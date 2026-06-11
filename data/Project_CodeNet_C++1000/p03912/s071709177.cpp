    
/* You are being watched. */


//~ while (clock() <= 69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")

#include <bits/stdc++.h>

//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")

using namespace std;

//~ #include <ext/pb_ds/assoc_container.hpp>
//~ #include <ext/pb_ds/tree_policy.hpp>
//~ using namespace __gnu_pbds;
//~ template <typename T>
//~ using ordered_set =
  //~ tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(x) (x).begin(), (x).end()
#define show(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << "\n"
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
//using li = __int128;
//using uli = unsigned __int128;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

double getTime() {
  return clock() / (double) CLOCKS_PER_SEC;
}

void read() {};

template<typename T, typename... Args>
void read(T& a, Args&... args) {
  cin >> a;
  read(args...);
}

void print() {};

template <typename T, typename... Args>
void print(T a, Args... args) {
  cout << a << " \n"[sizeof...(args) == 0];
  print(args...);
}

const int N = 1e5 + 5;

vector <int> g[N];
int cnt[N];

void solve() {
  int n; cin >> n;
  int m; cin >> m;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    g[x % m].push_back(x);
  }
  int ans = 0;
  for(int i = 0; i < m; i++) {
    sort(g[i].begin(), g[i].end());
    int pv = -1;
    for(auto x : g[i]) {
      if(pv == x) {
        cnt[i]++;
        pv = -1;
      } else pv = x;
    }
  }
  ans += (int)g[0].size() / 2;
  if(m % 2 == 0) ans += (int)g[m / 2].size() / 2;
  for(int p = 1, q = m - 1; p < q; p++, q--) {
    int cur = min(g[p].size(), g[q].size());
    ans += cur;
    ans += min(cnt[p], ((int)g[p].size() - cur) / 2);
    ans += min(cnt[q], ((int)g[q].size() - cur) / 2);
  }
  print(ans);
}

int main() {
  int t; t = 1;
  while(t--) solve();
}


