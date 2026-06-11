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

int N; 
ll K, Bit[40], A[int(1e5+5)], B[int(1e5+5)];
bool k[40];
ll DP[40], ans[40];

int main(){
  cin >> N >> K;
  Bit[39] = 1;
  for (int i = 38; i >= 0; i--) Bit[i] = Bit[i+1] * 2;

  ll num = K;
  for (int i = 39; i >= 0; i--){
    if (num % 2 != 0) k[i] = true;
    num /= 2;
  }

  for (int i = 0; i < 40; i++){
    ll now = 0;
    for (int j = 0; j < i; j++){
      if (k[j]) now += Bit[j];
    }
    for (int j = i + 1; j < 40; j++){
      now += Bit[j];
    }
    DP[i] = now;
  }

  for (int i = 0; i < N; i++){
    cin >> A[i] >> B[i];
    for (int j = 0; j < 40; j++){
      if ((A[i] | DP[j]) <= K) ans[j] += B[i];
    }
  }

  sort(ans, ans + 40, greater<ll>());
  cout << ans[0] << endl;

  return 0;
}
