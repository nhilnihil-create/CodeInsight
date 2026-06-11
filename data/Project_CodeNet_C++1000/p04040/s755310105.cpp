#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

const int N_MAX = 200005;

ll inv[N_MAX],fac[N_MAX],finv[N_MAX];
void make(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<N_MAX;i++){
        inv[i]=mod-inv[mod%i]*(mod/i)%mod;
        fac[i]=fac[i-1]*(ll) i%mod;
        finv[i]=finv[i-1]*inv[i]%mod;
    }
}

ll Combination(ll C, ll D){
	if(C==0 && D==0) return 1;
    if(C<D||C<1) return 0;
    return fac[C]*(finv[D]*finv[C-D]%mod)%mod;
}

int main(){
	ll H, W, A, B;
	cin >> H >> W >> A >> B;
	make();
	ll res = 0;
	REP(i, W-B){
		int tate1 = H-A-1;
		int yoko1 = B+i;
		int tate2 = A-1;
		int yoko2 = W-B-i-1;
		res += (Combination(tate1+yoko1, tate1) * Combination(tate2+yoko2, tate2))%mod;
		res %= mod;
	}
	cout << res << endl;

    return 0;
}