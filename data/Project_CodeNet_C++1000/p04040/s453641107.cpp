#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 1000000007;
const ll INF = 4611686018427387903;
#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

const int MAX=510000;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit(){
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
	for (int i=2;i<MAX;i++){
		fac[i]=fac[i-1]*i%MOD;
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		finv[i]=finv[i - 1]*inv[i]%MOD;
	}
}
long long COM(int n, int k){
	if(n<k) return 0;
	if(n<0||k<0) return 0;
	return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

int main(){
	COMinit();
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	ll ans=0;
	for(int i=b;i<w;i++){
		ans+=COM(h-a-1+i,i)*COM(a-1+w-i-1,a-1)%MOD;
		ans%=MOD;
	}
	cout << ans << endl;
	return 0;
}