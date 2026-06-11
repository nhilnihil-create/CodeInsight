#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

const int MAX = 510000;
const int MOD = 1000000007;

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
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	COMinit();
	int H,W,A,B;
	cin >> H >> W >> A >> B;
	ll ans = 0;
	//1行目からH-A行目までについてi行目の移動回数は
	//右への移動回数は(B-1)回なので 場合の数は(B-1)+(i-1)_C_B-1;
	for(int i=1;i<=H-A;i++){
		ll t = COM(B-1+(i-1),B-1);
		//またi行目について右下までいく場合の数は
		//下にH-i-1回移動して、右にW-B-1回移動するので
		ans += t*COM( (H-i) + W-B-1,H-i);
		ans %= MOD;
	}
	cout << ans << endl;
}