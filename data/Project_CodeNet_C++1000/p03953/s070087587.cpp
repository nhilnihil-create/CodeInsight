#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
int n,m,x[N],a[N];
int b[N],vis[N],tmp[N],t;
int ans[N];
LL K;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	scanf("%d%lld",&m,&K);
	for (int i=1;i<n;i++)
		b[i]=i;
	for (int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		swap(b[a[i]-1],b[a[i]]);
	}
	memset(vis,0,sizeof vis);
	for (int i=1;i<n;i++){
		if (vis[i])
			continue;
		vis[i]=1;
		tmp[t=1]=i;
		for (int j=b[i];j!=i;j=b[j])
			vis[tmp[++t]=j]=1;
		int d=K%t;
		for (int j=1;j<=t;j++)
			ans[tmp[j]]=tmp[(j-1+d)%t+1];
	}
	LL tot=x[1];
	printf("%lld\n",tot);
	for (int i=1;i<n;i++)
		printf("%lld\n",tot+=x[ans[i]+1]-x[ans[i]]);
	return 0;
}