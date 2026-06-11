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
  vector<P> a(N);
  rep(i, N) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a.begin(), a.end());
  ll ans = 0;
  //rep(i, N) cout << a[i].first << " " << a[i].second << endl;
  rep(i, N){
    if (a[i].second % 2 == 0 && (i + 1) % 2 != 0) ans++;
  }
  cout << ans << endl;
}
