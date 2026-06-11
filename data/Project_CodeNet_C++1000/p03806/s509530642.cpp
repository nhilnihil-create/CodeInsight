#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;

#define fi first
#define se second

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);

void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int N, Ma, Mb;
ll A[45], B[45], C[45];
ll DP[45][405][405];

int main(){
  cin >> N >> Ma >> Mb;
  for (int i = 1; i <= N; i++){
    cin >> A[i] >> B[i] >> C[i];
  }

  fill((ll*)DP, (ll*)(DP + N + 1), 1e18);
  DP[0][0][0] = 0;

  for (int i = 1; i <= N; i++){
    for (int j = 0; j <= 400; j++){
      for (int k = 0; k <= 400; k++){
        DP[i][j][k] = DP[i-1][j][k];
      }
    }

    for (int j = 0; j <= 400; j++){
      for (int k = 0; k <= 400; k++){
        if (DP[i-1][j][k] == 1e18) continue;
        DP[i][j+A[i]][k+B[i]] = min(DP[i-1][j][k] + C[i], DP[i][j+A[i]][k+B[i]]);
      }
    }
  }

  ll ans = 1e18;
  for (int i = 1; i <= 400; i++){
    int a = Ma * i, b = Mb * i;
    if (a > 400 || b > 400) break;
    ans = min(ans, DP[N][a][b]);
  }
  if (ans == 1e18) ans = -1;
  cout << ans << endl;

  return 0;
}
