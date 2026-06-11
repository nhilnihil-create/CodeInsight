#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;

typedef long long lli;
typedef pair<int,int> pii;

const int MAXN=100000,mod=1e9+7;
int n,m,a[MAXN],b[MAXN];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	for(int i=0;i<m;i++) scanf("%d",b+i);

	lli as=0,bs=0;
	for(int i=0;i<n-1;i++) as=(as+1ll*(a[i+1]-a[i])*(i+1)%mod*(n-i-1)%mod)%mod;
	for(int i=0;i<m-1;i++) bs=(bs+1ll*(b[i+1]-b[i])*(i+1)%mod*(m-i-1)%mod)%mod;

	printf("%lld\n",as*bs%mod);
	
	return 0;
}
