#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
static const int INF = 2000000000;



int main(){
  ll n, T;
  cin >> n >> T;
  vector<ll> t(n);
  rep(i, n) cin >> t[i];
  ll ans = 0;
  for (int i = 1; i < n; i++){
    ll sa = t[i] - t[i-1];
    if (sa >= T) ans += T;
    else ans += sa;
  }
  ans += T;
  cout << ans << endl;
}