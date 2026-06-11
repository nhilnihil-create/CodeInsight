#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 201000, p = 1e9+7;
int fac[N], inv[N];

inline int C(int n, int m) {return (ll)fac[n] * inv[m]%p * inv[n-m]%p;}
inline int qpow(int A, int B) {
	int res = 1; while(B) {
		if(B&1) res = (ll)res * A%p;
		A = (ll)A * A%p, B >>= 1;
	} return res;
}

int n, m, a, b;

int main() {
	scanf("%d%d%d%d",&n,&m,&a,&b);
	int L = n + m;
	fac[0] = 1;
	for(int i=1;i<=L;++i) fac[i] = (ll)fac[i-1] * i%p;
	inv[L] = qpow(fac[L], p-2);
	for(int i=L;i;--i) inv[i-1] = (ll)inv[i] * i%p;
	
	int ans = 0;
	for(int i=1;i<=n-a;++i)
		ans = (ans + (ll)C(i+b-2, i-1) * C(n-i+m-b-1, n-i))%p;
	printf("%d\n", ans);
	return 0;
}