#include <bits/stdc++.h>
using namespace std;

typedef long long lli;
const int MOD=1e9+7,MAXN=1000000;

int n;
int main() {
	scanf("%d",&n);

	int ps=n-1,ans=n,pr=n,ppr=1;
	for(int i=2;i<=n;i++) {
		ans = (pr + ps + 1ll*(n-1)*(n-1)%MOD)%MOD;
		ps = (1ll*ps + ppr - 1 + MOD)%MOD;
		ppr = pr;
		pr = ans;
		pr = ans;
	}
	printf("%d\n",ans);
	
	return 0;
}
