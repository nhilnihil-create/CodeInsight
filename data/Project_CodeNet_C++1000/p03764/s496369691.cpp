#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

using namespace std;

const int md = 1e9 + 7;

int m, n;
int x[111111], p[3];

int main(){
//	freopen("input.inp", "r", stdin);
	scanf("%d%d",&n,&m);
	for(int q = 1; q <= 2; ++q){
		if (q == 2) n = m;
		long long tmp = 0, al = 0;
		for(int i = 1; i <= n; ++i){
			scanf("%d",&x[i]);
			tmp += x[i] - x[1];
			tmp %= md;
		}
		for(int i = 1; i < n; ++i){
			p[q] += tmp;
			p[q] %= md;
			tmp -= 1ll * (n - i) * (x[i + 1] - x[i]) % md;
			tmp += md;
			tmp %= md;
		}
	}
	printf("%lld", 1ll * p[1] * p[2] % md);
	return 0;
}