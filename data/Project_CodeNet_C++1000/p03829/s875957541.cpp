#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N; cin >> N;
  ll A,B; cin >> A >> B;
  
  ll ans = 0;
  ll before; cin >> before;
  rep(i, N - 1) {
    ll x; cin >> x;
    ll diff = x - before;
    if(diff * A > B) {
      ans += B;
    } else {
      ans += diff * A;
    }
    before = x;
  }

  cout << ans << endl;
}
