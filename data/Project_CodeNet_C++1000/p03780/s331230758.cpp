#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N, K; cin >> N >> K;
  int a[N+1] = {}; rep(i,N) cin >> a[i]; sort(a,a+N+1);
  int l = 0, r = 0; while (a[r]<K&&r!=N+1) r++;
  while (l!=r) {
    int mid = (l+r)/2;

    bool dp[N+2][K] = {}; dp[0][0] = true;
    rep(i,N+1) {
      rep(j,K) {
        if (i==mid) dp[i+1][j] = dp[i][j];
        else {
          dp[i+1][j] = dp[i][j];
          if (j>=a[i]) dp[i+1][j] |= dp[i][j-a[i]];
        }
      }
    }
    // cout << mid << endl;
    // rep(i,K) cout << dp[N+1][i] << " "; cout << endl;
    bool noneed = false;
    repr(i,K-a[mid],K) noneed |= dp[N+1][i];
    if (noneed) r = mid;
    else l = mid+1;
  }
  int result = l-1;
  cout << result << endl;
  return 0;
}