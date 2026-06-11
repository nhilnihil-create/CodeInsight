// includes
#include <cstdio>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <climits>
#include <bitset>
#include <list>
#include <random>

// macros
#define ll long long int
#define pb push_back
#define mk make_pair
#define pq priority_queue
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for(int i=((int)(n)-1);i>=0;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())

using namespace std;

//  types
typedef pair<int, int> P;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
 
// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1e9 + 7;

// solve
template <class T>bool chmax(T &a, const T &b){if(a < b){a = b; return 1;} return 0;}
template <class T>bool chmin(T &a, const T &b){if(a > b){a = b; return 1;} return 0;}

template<typename T, typename E>
struct SegmentTree_ {
  function<T(T, T)> f;
  function<T(T, E)> g;
  int n;
  T def;
  vector<T> vec;
  SegmentTree_(){}
  SegmentTree_(int n_, function<T(T, T)> f_, function<T(T, E)> g_, T def_, vector<T> v=vector<T>()){
    f = f_;
    g = g_;
    def = def_;

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
  void update(int k, E val){
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

bool ma[100001];

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n)cin >> a[i];
  ma[0] = true;
  ll maxi = a[0];
  ll sum = a[0];
  FOR(i, 1, n){
    if(maxi < a[i]){
      ma[i] = true;
      maxi = a[i];
    }else{
      ma[i] = false;
    }
    sum += a[i];
  }
  SegmentTree<ll, ll> segtree = SegmentTree<ll, ll>(n, [](ll a, ll b){return a + b;},
      [](ll a,ll b){return b;}, 0, vector<ll>());
  SegmentTreeI seg = SegmentTreeI(n, [](int a, int b){return a + b;},
      [](int a,int b){return b;}, 0, vector<int>());
  vector<ll> b = a;
  sort(all(b));
  UNIQUE(b);
  unordered_map<ll, int> mp;
  rep(i, sz(b)){
    mp[b[i]] = i;
  }
  vector<ll> ans(n, 0);
  for(int i = n - 1; i >= 0; i--){
    int index = mp[a[i]];
    ll res = 0;
    if(ma[i]){
      res += segtree.query(index + 1, n);
      res -= a[i] * seg.query(index + 1, n);
    }
    ans[i] = res;
    segtree.update(index, a[i] * (ll)(seg.query(index, index + 1) + 1));
    seg.update(index, seg.query(index, index + 1) + 1);
  }
  ll rem = sum;
  rep(i, n){
    if(ma[i]){
      cout << rem - ans[i] << endl;
      rem = ans[i];
    }else{
      cout << 0 << endl;
    }
  }
	return 0;
}
