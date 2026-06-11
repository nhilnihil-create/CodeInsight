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




int N;
vector<ll> a;
ll d[100010];
bool b[100010];

int main () {
  cin >> N;

  rep(i, N) {
    ll tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  sort(All(a));

  Rep(i, N) {
    d[i+1] = a[i] + d[i];
  }

  rep(i, N-1) {
    if (a[i] <= d[i] * 2) {
      b[i] = true;
    }
  }

  int ans = 1;

  for (int k=N-1;k>=1;--k) {
    if (b[k]) {
      ans++;
    } else {
      break;
    }
  }

//  Rep(i, N) {
//    cout << a[i] << "\n";
//  }
//
//  rep(i, N) {
//    cout << d[i] << "\n";
//  }
//
//  rep(i, N-1) {
//    cout << b[i] << "\n";
//  }
  cout << ans << "\n";

}