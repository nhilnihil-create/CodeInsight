// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+5;
int n,m;
int x[maxn];
int a[maxn],b[maxn],c[maxn];
LL K;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	for (int i=1;i<n;i++) a[i]=b[i]=i;
	scanf("%d%lld",&m,&K);
	for (int tmp,i=1;i<=m;i++){
		scanf("%d",&tmp);
		swap(a[tmp-1],a[tmp]);
	}
	for (;K;K>>=1){
		if (K&1) for (int i=1;i<n;i++) b[i]=a[b[i]];
		for (int i=1;i<n;i++) c[i]=a[a[i]];
		for (int i=1;i<n;i++) a[i]=c[i];
	}
	LL ans=x[1];
	for (int i=1;i<=n;i++){
		printf("%lld.0\n",ans);
		ans+=x[b[i]+1]-x[b[i]];
	}
	return 0;
}