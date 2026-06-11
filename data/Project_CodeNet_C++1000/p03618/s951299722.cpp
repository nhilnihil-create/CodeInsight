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

ll choose(ll n){
  return n * (n - 1) / 2;
}

int main(){
  string A; cin >> A;

  ll N = A.length();
  vector<ll> vec(26);
  rep(i, N) vec[A[i] - 'a']++;
  ll ans = choose(N);
  rep(i, 26){
    ans -= choose(vec[i]);
  }
  cout << ans + 1 << endl;
}
