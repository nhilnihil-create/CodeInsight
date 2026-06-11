#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

ll gcd(ll x, ll y){
  return y == 0 ? x : gcd(y, x % y);
}

int main(){
  int N, K; cin >> N >> K;
  vector<int> a(N); rep(i, N) cin >> a[i];

  int g = a[0];
  for (int i = 1; i < N; ++i){
    g = gcd(g, a[i]);
  }
  int m = 0;
  for (int i = 0; i < N; ++i){
    m = max(m, a[i]);
  }
  if (gcd(K, g) == g && K <= m) cout << "POSSIBLE" << endl;
  else cout << "IMPOSSIBLE" << endl;
}
