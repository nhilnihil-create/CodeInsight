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
  ll Q, H, S, D; cin >> Q >> H >> S >> D;
  ll N; cin >> N;

  vector<ll> liter(2);
  liter[0] = min({D, 2 * S, 4 * H, 8 * Q});
  liter[1] = min({S, 2 * H, 4 * Q});
  vector<ll> num(2);
  num[0] = N / 2;
  num[1] = N % 2;
  ll ans = num[0] * liter[0] + num[1] * liter[1];
  cout << ans << endl;
}
