#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(i, n) for (int i = n; i >= 0; --i) 
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const static int MOD = 1000000000 + 7;
const static int INT_INF = 999999999;
const static llong INF = 1LL << 60;
const static double eps = 1e-6;
const static int dx[] = {1, 0, -1, 0};
const static int dy[] = {0, 1, 0, -1};

const int MAX = 510000;

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

signed main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w, a, b;
    cin >> h >> w >> a >> b;
    COMinit();
    llong res = 0;
    rep(i, h - a) {
        res += COM(b-1+i,b-1)*COM(w-b-1+(h-1-i),w-b-1);
		res%=MOD;
    }

    cout << res << endl;
    return 0;
}