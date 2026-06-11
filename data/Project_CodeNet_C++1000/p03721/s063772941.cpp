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
  ll N, K; cin >> N >> K;
  vector<P> array(N);
  rep(i, N){
    cin >> array[i].first >> array[i].second;
  }
  sort(array.begin(), array.end());

  ll ans = 0;
  ll tot = 0;
  rep(i, N){
    tot += array[i].second;
    if (tot >= K) {
      ans = array[i].first;
      break;
    }
  }
  cout << ans << endl;
}
