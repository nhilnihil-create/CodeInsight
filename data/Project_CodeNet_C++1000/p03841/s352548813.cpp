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

int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int m; cin >> m;
  int n = m * m;
  vector<int> a(m);
  for(int i = 0; i < m; i++) cin >> a[i], a[i]--;
  vector<int> ord(m);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int x, int y) {
      return a[x] < a[y];
      });
  auto b = a;
  b.emplace_back(-1);
  b.emplace_back(n);
  sort(begin(b), end(b));
  vector<int> c(m + 1);
  for(int i = 1; i <= m + 1; i++) c[i-1] = b[i] - b[i-1] - 1;
  vector<int> ans;
  int rest = 0;
  vector<int> req;
  dump(1);
  for(int i = 0; i < m; i++) {
    int x = ord[i];
    dump(x);
    int r = m - 1 - x;
    int l = x;
    rest += c[i];
    for(int j = 0; j < l; j++) {
      if(rest <= 0) return (cout << "No" << endl, 0);
      rest--;
      ans.emplace_back(x);
    }
    for(int j = 0; j < r; j++) {
      req.emplace_back(x);
    }
  }
  dump(1);
  ans.insert(end(ans), begin(req), end(req));
  int head = 0;
  int id = 0;
  vector<int> res;
  vector<int> cnt(m);
  for(int i = 0; i < n; i++) {
    if(head < m && a[ord[head]] == i) {
      if(cnt[ord[head]] != ord[head]) return (cout << "No" << endl, 0);
      cnt[ord[head]]++;
      res.emplace_back(ord[head]+1);
      head++;
    } else {
      cnt[ans[id]]++;
      res.emplace_back(ans[id] + 1);
      id++;
    }
  }
  dump(1);
  cout << "Yes" << endl;
  cout << res << endl;
}


