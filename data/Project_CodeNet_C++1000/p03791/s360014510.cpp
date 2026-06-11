// includes
#include <bits/stdc++.h>
using namespace std;

// macros
#define pb emplace_back
#define mk make_pair
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define irep(itr, st) for(auto itr = (st).begin(); itr != (st).end(); ++itr)
#define irrep(itr, st) for(auto itr = (st).rbegin(); itr != (st).rend(); ++itr)
#define whole(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define bit(n) (1LL<<(n))
// functions
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for(auto &v: vec)is >> v; return is;}
template <typename T> ostream &operator<<(ostream &os, const vector<T>& vec){for(int i = 0; i < vec.size(); i++){ os << vec[i]; if(i + 1 != vec.size())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_set<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T>& st){for(auto itr = st.begin(); itr != st.end(); ++itr){ os << *itr; auto titr = itr; if(++titr != st.end())os << " ";} return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &p){os << p.first << " " << p.second; return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const unordered_map<T1, T2> &mp){for(auto itr = mp.begin(); itr != mp.end(); ++itr){ os << itr->first << ":" << itr->second; auto titr = itr; if(++titr != mp.end())os << " "; } return os;}
//  types
using ll = long long int;
using P = pair<int, int>;
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1000000007;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
// io
struct fast_io{
  fast_io(){ios_base::sync_with_stdio(false); cin.tie(0); cout << fixed << setprecision(20);}
} fast_io_;

template<typename T, typename E>
struct SegmentTree_ {
  function<T(T, T)> f; // aggregate function
  function<T(T, E)> g; // update function
  int n;
  T def;
  vector<T> vec;
  SegmentTree_(){}
  SegmentTree_(int n_, function<T(T, T)> f, function<T(T, E)> g, T def, vector<T> v=vector<T>()): f(f), g(g), def(def){

    // initialize vector
    n = 1;
    while(n < n_){
      n *= 2;
    }
    vec = vector<T>(2*n -1, def);

    // initialize segment tree
    for(int i = 0; i < v.size(); i++){
      vec[i + n - 1] = v[i];
    }
    for(int i = n - 2; i >= 0; i--){
      vec[i] = f(vec[2*i+1], vec[2*i+2]);
    }
  }
  void update(int k, const E &val){
    k = k + n - 1;
    vec[k] = g(vec[k], val);
    while(k > 0){
      k = (k - 1) / 2;
      vec[k] = f(vec[2*k+1], vec[2*k+2]);
    }
  }
  // [l, r) -> [a, b) (at k)
  T query(int a, int b, int k, int l, int r){
    if(r <= a || b <= l)return def;
    if(a <= l && r <= b)return vec[k];
    T ld = query(a, b, 2*k+1, l, (l+r)/2);
    T rd = query(a, b, 2*k+2, (l+r)/2, r);
    return f(ld, rd);
  }
  T query(int a, int b){
    return query(a, b, 0, 0, n);
  }
};

template<typename T, typename E>
using SegmentTree = struct SegmentTree_<T, E>;
using SegmentTreeI = SegmentTree<int, int>;
using SegmentTreeL = SegmentTree<long long, long long>;


int main(int argc, char const* argv[])
{
  int n; cin >> n;
  vector<ll> x(n); cin >> x; rep(i, n)x[i]--;
  SegmentTreeL seg = SegmentTreeL(n, [](ll a, ll b){return max(a, b);},
                                  [](ll a,ll b){return max(0LL, b);}, 0, vector<ll>());
  
  seg.update(0, (- x[0] + 1) / 2);
  ll res = 1;
  FOR(i, 1, n){
    ll ld = max(-1LL, (2 * i - x[i] - 1 + 1) / 2 - 1);
    ll rd = i;
    while(rd - ld > 1){
      ll md = (rd + ld) / 2;
      ll tmp = seg.query(md, i);
      if(tmp <= md)rd = md;
      else ld = md;
    }
    //cerr << rd << endl;
    res = res * (ll)(i - rd + 1) % mod;
    seg.update(i, (2 * i - x[i] + 1) / 2);
  }
  cout << res << endl;
  return 0;
}
