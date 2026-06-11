#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=200005;
ll a[N],f[N],g[N];
ll ans;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
		f[i]=f[i-1]+a[i];
	for(int i=n;i;i--)
		g[i]=g[i+1]+a[i];
	ans=abs(f[1]-g[2]);
	for(int i=3;i<=n;i++)
		ans=min(abs(f[i-1]-g[i]),ans);
	printf("%lld",ans);
	return 0;
}