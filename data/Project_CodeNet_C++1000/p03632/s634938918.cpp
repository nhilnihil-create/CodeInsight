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
  int A, B, C, D; cin >> A >> B >> C >> D;
  vector<int> a, b;
  for (int i = A; i <= B; ++i) a.push_back(i);
  for (int i = C; i <= D; ++i) b.push_back(i);
  int ans = 0;
  rep(i, (int)a.size()){
    rep(j, (int)b.size()){
      if (a[i] == b[j]) {
        ans++;
        //cout << a[i] << " " << b[j] << endl;
      }
    }
  }
  if (ans != 0) cout << ans - 1 << endl;
  else cout << 0 << endl;
}
