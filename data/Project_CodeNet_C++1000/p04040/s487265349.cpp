#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
#define rep(i, n) for(ll i = 0;i < n;i++)
#define all(i) i.begin(), i.end()
template<class T, class U> bool cmax(T& a, U b) { if (a<b) {a = b; return true;} else return false; }
template<class T, class U> bool cmin(T& a, U b) { if (a>b) {a = b; return true;} else return false; }

// http://drken1215.hatenablog.com/entry/2018/06/08/210000
constexpr int MAX = 510000;
constexpr ll MOD = 1e9+7;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll H(ll n, ll k) {
  return COM(n+k, k);
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);

  COMinit();
  ll h, w, a, b;
  cin >> h >> w >> a >> b;
  ll ans = 0;
  rep(i, h-a) {
    ans += (H(b-1, i) * H(h-i-1, w-b-1))%MOD;
    ans %= MOD;
  }

  cout << ans << endl;
}
