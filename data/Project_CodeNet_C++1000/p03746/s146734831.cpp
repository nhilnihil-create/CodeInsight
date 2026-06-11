#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) {
  return '"' + s + '"';
}
string to_string(const char* s) {
  return to_string((string) s);
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
#ifdef LOCAL
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif
const long long mod = 1e9+7; // CHECK
long long power(long long a, long long b, long long m = mod) {
    if(b < 0) {
        return power(power(a, -b), mod-2);
    }
    long long x = 1;
    while(b) {
        if(b & 1) {
            x = 1ll * x * a % m;
        }
        a = 1ll * a * a % m;
        b /= 2;
    }
    return x;
}
#define ll long long
const int INT_INF = 1e9+9;
const ll LL_INF = 2e18;
const int N = 3e5+9; // check N, mod
set<int> g[N];
vector<int> path[2];
int vis[N];
void dfs(int u, int k) {
    vis[u] = 1;
    path[k].push_back(u);
    int v = -1;
    while (!g[u].empty()) {
        v = *g[u].begin();
        g[u].erase(v);
        g[v].erase(u);
        if (vis[v] == 0) {
            dfs(v, k);
            break;
        }
    }
}
signed main() {  
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    dfs(1, 0);
    // dbg(path[0]);
    dfs(1, 1);
    // dbg(path[1]);
    reverse(path[1].begin(), path[1].end());
    path[1].pop_back();
    cout << path[0].size() + path[1].size() << '\n';
    for (int k = 1; k >= 0; k--) {
        for (int i: path[k]) cout << i << " ";
    }
    cout << endl;
    



    

    

    return 0;
}

