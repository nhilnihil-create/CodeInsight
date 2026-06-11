#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;

typedef long long ll;

#define INF 10e17
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { debug(itr); }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

int main() {
  ll n, L, sum = 0;
  cin >> n >> L;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
  }

  bool flag = true;
  int t = 0;

  rep(i, n-1) {
    if (a[i] + a[i+1] >= L) {
      t = i + 1;
      flag = false;      
    }
  }

  if (flag) {
    cout << "Impossible" << endl;
    return 0;
  }

  cout << "Possible" << endl;
  for (int i = 1; i < t; ++i) {
    cout << i << endl;
  }

  for (int i = n-1; i > t; --i) {
    cout << i << endl;
  }

  cout << t << endl;
}
