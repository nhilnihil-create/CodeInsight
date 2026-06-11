#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// #undef DEBUG
// #define DEBUG
/// {{{ DEBUG --- ///
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if(&o == &cerr) { o << '{'; for(size_t i = 0; i < v.size(); i++) o << v[i] << (i + 1 != v.size() ? ", " : ""); o << "}"; } else { for(size_t i = 0; i < v.size(); i++) o << v[i] << (i + 1 != v.size() ? " " : ""); } return o; }
#ifdef DEBUG
#ifdef USE_COUT
#define dump(...) (cout<<"["<<__LINE__<< "] "<<#__VA_ARGS__<<" = "<<make_tuple(__VA_ARGS__)<<"\n")
#else
#define dump(...) (cerr<<"["<<__LINE__<< "] "<<#__VA_ARGS__<<" = "<<make_tuple(__VA_ARGS__)<<"\n")
#endif
template<int n, class...T> typename enable_if<(n>=sizeof...(T))>::type _ot(ostream &, tuple<T...> const &){}
template<int n, class...T> typename enable_if<(n< sizeof...(T))>::type _ot(ostream & os, tuple<T...> const & t){ os << (n==0?"":", ") << get<n>(t); _ot<n+1>(os, t); }
template<class...T> ostream & operator<<(ostream &o, tuple<T...> const &t){ o << "("; _ot<0>(o, t); o << ")"; return o; }
template<class T, class U> ostream & operator<<(ostream &o, pair<T, U> const &p) { o << "(" << p.first << ", " << p.second << ")"; return o; }
#else
#define dump(...) (0)
#endif
/// }}}--- ///

/// --- Union Find Library {{{ ///

struct UF {
  int n;
  vector<int> par, rank;
  UF(int n): n(n), par(n, -1), rank(n, 0) {}
  int find(int x) {
    return par[x] < 0 ? x : par[x] = find(par[x]);
  }
  int size(int x) {
    return -par[find(x)];
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(rank[a] > rank[b]) swap(a, b);
    par[b] += par[a];
    par[a] = b;
    if(rank[a] == rank[b]) rank[b]++;
  }
};

/// }}}--- ///

const int N = 1e5;
vector<int> g[N];
int n, m;

int used[N];
int dep[N];
int ch[N];
bool dfs(int i, int p = -1, int d = 0) {
  used[i] = 1;
  dep[i] = d;
  int r = 0;
  ch[i] = 1;
  for(int j : g[i]) if(j != p) {
    if(used[j]) {
      r |= dep[j] % 2 == dep[i] % 2;
    } else {
      r |= dfs(j, i, d + 1);
      ch[i] += ch[j];
    }
  }
  return r;
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  ll on0 = 0, en0 = 0;
  ll on = 0, en = 0;
  {
    UF uf(n * 3);
    for(int i = 0; i < n; i++) for(int j : g[i]) if(i < j) {
      uf.unite(i, j + n);
      uf.unite(j, i + n);
      uf.unite(i + n, j + n * 2);
      uf.unite(j + n, i + n * 2);
    }
    set<int> st;
    for(int i = 0; i < n; i++) st.emplace(uf.find(i));
    en0 = st.size();
    for(int i = 0; i < n; i++) st.emplace(uf.find(i + n));
    for(int i = 0; i < n; i++) if(!st.count(uf.find(i + n * 2))) en++;
  }
  {
    UF uf(n * 3);
    for(int i = 0; i < n; i++) for(int j : g[i]) if(i < j) {
      uf.unite(i, j + n);
      uf.unite(j, i + n);
      uf.unite(i + n, j + n * 2);
      uf.unite(j + n, i + n * 2);
      uf.unite(j + n * 2, i);
      uf.unite(i + n * 2, j);
    }
    set<int> st;
    for(int i = 0; i < n; i++) st.emplace(uf.find(i));
    on0 = st.size();
    // for(int i = 0; i < n; i++) st.emplace(uf.find(i + n));
    for(int i = 0; i < n; i++) if(!st.count(uf.find(i + n * 2))) on++;
  }
  
  ll ans = 0;
  dump(en0, en, on0, on);
  for(int i = 0; i < n; i++) if(!used[i]) {
    if(g[i].size() == 0) {
      ans += n;
    } else if(dfs(i)) {
      ans += on0 + on * (ch[i] - 1);
    } else {
      ans += en0 + en * (ch[i] - 1);
    }
  }
  cout << ans << endl;
}

