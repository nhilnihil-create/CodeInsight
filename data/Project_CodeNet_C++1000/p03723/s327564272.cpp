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
  ll A, B, C; cin >> A >> B >> C;
  if (A == B && B == C && C == A && A % 2 == 0) cout << -1 << endl;
  else if (A == B && B == C && C == A && A % 2 != 0) cout << 0 << endl;
  else {
    ll ans = 0;
    while (A % 2 == 0 && B % 2 == 0 && C % 2 == 0){
      ll tmp1 = A, tmp2 = B, tmp3 = C;
      A = (tmp2 + tmp3) / 2;
      B = (tmp1 + tmp3) / 2;
      C = (tmp1 + tmp2) / 2;
      ++ans;
    }
    cout << ans << endl;
  }
}
