#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define BUFF ios::sync_with_stdio(0);

typedef long long int ll;
typedef long double ld;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef pair < int, int > ii;
typedef vector < ii > vii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MOD = 1e9+7;
const ld pi = acos(-1);

ll dp[5000][51] = {0ll};
int main() { BUFF
  ll n, a; cin >> n >> a;
  vi x(n); for(auto &it : x) cin >> it;
  for(int i=0; i<n; i++) {
    for(int j=n; j>=2; j--) {
      for(int k=1; k<=2500; k++) {
        int prev = k - x[i];
        if(prev < 0) continue;
        dp[k][j] += dp[prev][j-1];
      }
    }
    dp[x[i]][1]++;
  }

  ll ans = 0;
  for(int i=1; i<=n; i++){
    ans += dp[a*i][i];
  }
  cout << ans << endl;
  return 0;
}
