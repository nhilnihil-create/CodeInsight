//arc058_d.cpp
//Wed Jul  3 21:40:49 2019

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

//nCk を1000000007で割った余りの計算。
const int MAX = 200000;
const int MOD = 1000000007;
ll fac[MAX], finv[MAX], inv[MAX];

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
ll COM(ll n, ll k){
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
	int h,w,a,b;
	cin >> h >> w >> a >> b;

	COMinit();

	ll ans = 0;
	for (int i=b+1;i<=w;i++){
		ans = (ans + (COM(h-a-1+i-1,max(h-a-1,i-1))*COM(a-1+w-i,max(a-1,w-i)))%MOD)%MOD;
//		cout << i<<endl;
	}


	cout << ans << endl;
//	printf("%.4f\n",ans);
}