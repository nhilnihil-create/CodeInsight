#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int MOD = 1000000007;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  ll ans = 0;

  rep(bit, (1 << n-1)) {
    ll temp = 0;
    ll prev = s[0] - '0';
    rep(i, n-1) {
      if (bit & (1 << i)) {
        temp += prev;
        prev = s[i+1] - '0';
      } else {
        prev = prev * 10 + (s[i+1] - '0');
      }
    }
    temp += prev;
    ans += temp;
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}