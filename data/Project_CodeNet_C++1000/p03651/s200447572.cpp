#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long int
#define INF 1e9
#define LINF 1e18
#define MOD 1000000007
#define PI 3.14159265359
#define EPS 1e-10
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll, ll>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

/**
 * Usage:
 * 
 * G[from].push_back(Edge(to, weight));
 * using Graph = vector<vector<Edge>>;
 * 
 */ 
struct Edge {
  int to;     
  ll weight; 
  Edge(int t, ll w) : to(t), weight(w) { }
};

/**
 * Usage:
 * 
 * chmin(old, new);
 * chmax(old, new);
 * 
 */ 
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<typename T>
void printv(vector<T>& v) {
  if (v.size() == 0) {
    cout << "\n";
    return;
  }

  Rep(i, v.size()) {
    cout << v[i] << ((i + 1 < v.size()) ? ' ' : '\n');
  }
}


 ll GCD(ll m, ll n) {
   if (m == 0) {
     return n;
   } 
   if (n == 0) {
     return m;
   }
 
   if (m >= n) {
     return GCD(m%n, n);
   } else {
     return GCD(m, n%m);
   }
 }

int N;
ll K;
ll a[110000];

int main () {
  cin >> N >> K;
  Rep(i, N) cin >> a[i];

  ll wa = a[0];
  ll saidai = a[0];

  for (int i=1;i<N;++i) {
    wa = GCD(wa, a[i]);
    saidai = max(a[i], saidai);
  }

  if (K % wa == 0 & K <= saidai) {
    cout << "POSSIBLE\n";
  } else {
    cout << "IMPOSSIBLE\n";
  }
}