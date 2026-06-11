#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
using namespace std;
typedef long long LL;
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
const int N=2e6;
int f[N],pre[N];
int main()
{
	const int mod=1e9+7;
	int n=gi(),i,ans;
	f[0]=pre[0]=1;ans=(n+1LL*(n-1)*(n-1))%mod;
	for (i=1;i<n;i++) {
		f[i]=i>=3?(f[i-1]+pre[i-3])%mod:f[i-1];
		if (i<n-1)
			ans=(ans+1LL*f[i]*(n-1)%mod*(n-1))%mod;
		ans=(ans+1LL*f[i]*(n-1))%mod;
		pre[i]=(f[i]+pre[i-1])%mod;
	}
	printf("%d\n",ans);
	return 0;
}
