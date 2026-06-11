#include <iostream>
#define ll long long
using namespace std;

ll mod=1000000007;
ll fac[510000], finv[510000], inv[510000];
void COMinit(ll m){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for (int i=2; i<510000; ++i){
        fac[i]=(fac[i-1]*i)%m;
        inv[i]=m-(inv[m%i]*(m/i))%m;
        finv[i]=(finv[i-1]*inv[i])%m;
    }
}
ll COM(int n, int k, ll m){
    if(n<k) return 0;
    if(n<0 || k<0) return 0;
    return (fac[n]*((finv[k]*finv[n-k])%m))%m;
}

int main() {
	int H, W, A, B;
	cin >> H >> W >> A >> B;
	COMinit(mod);
	ll ans=0;
	for(int i=0; i+A<H; ++i){
	    ans=(ans+(COM(i+B-1, i, mod)*COM(H-i+W-B-2, H-i-1, mod))%mod)%mod;
	}
	cout << ans << endl;
	return 0;
}
