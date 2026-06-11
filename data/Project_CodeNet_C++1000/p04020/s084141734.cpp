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

int main(){
  int N; cin >> N;
  vector<int> a(N); rep(i, N) cin >> a[i];

  vector<ll> que;
  rep(i, N){
    ll tot = 0;
    while (i < N && a[i] != 0) tot += a[i], ++i;
    que.push_back(tot);
  }
  ll ans = 0;
  rep(i, que.size()) ans += que[i] / 2;
  cout << ans << endl;
}
