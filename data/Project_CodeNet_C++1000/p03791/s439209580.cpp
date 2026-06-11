#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
int main() {
  cin.tie(0);
  cout << fixed << setprecision(10);
  int n; cin >> n;
  int cnt = n;
  ll ans = 1;
  int hoge = 0;
  for(int i=0;i<n;++i) {
    int tmp;cin >> tmp;
    if(tmp < 2*i+1-2*hoge) {
      ans *= i+1-hoge;
      ans %= MOD;
      cnt--;
      hoge++;
    }
  }
  while(cnt > 1) {
    ans *= cnt;
    ans %= MOD;
    cnt--;
  }
  cout << ans << endl;
}
