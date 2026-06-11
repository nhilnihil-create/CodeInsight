#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<utility>
#include<queue>
using namespace std;
#define REP(i, a,b) for(i=a;i<b;i++) 
#define REP1(i,b,a) for(i=b-1;i>=a;i--)
#define output(x) cout<<x<<endl;
#define pb(x) push_back(x);
typedef long long int ll;
const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

// 二項係数計算
long long COM(int n, int k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long ruijyo(ll n, ll k) {
	if (k == 0) {
		return 1;
	}
	ll sum = 1;
	ll i;
	REP(i, 0, k) {
		sum *= n;
		sum %= MOD;
	}
	return sum;
}

int main()
{
	ll  i, j, k, l, m,n, sum, flag, N,  M, K, H, W, B,C,D;
	sum = 0;
	flag = 0;
	ll A[7];
	
	REP(i, 0, 7) {
		cin >> A[i];
	}
	ll ans,ans1;
	ans =ans1= 0;
	if (A[0] >= 1 && A[3] >= 1 && A[4] >= 1) {
		ans += 3;
		ans += ((A[0] - 1) / 2) * 2 + (A[1]) + ((A[3] - 1) / 2) * 2 + ((A[4] - 1) / 2) * 2;
		ans1 += (A[0] / 2) * 2 + (A[1]) + (A[3] / 2) * 2 + (A[4] / 2) * 2;

		k = fmax(ans, ans1);
		output(k);
	}
	else {
		output((A[0] / 2) * 2 + (A[1]) + (A[3] / 2) * 2 + (A[4] / 2) * 2);
	}
	
	return 0;
	

	
}











