#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100005;
int a[MAXN],n,m,p[MAXN],ret[MAXN],t[MAXN];
typedef long long ll;
ll k,d[MAXN];
inline void ksm(ll k)
{
	for(int i=1;i<=n;++i)ret[i]=i;
	while(k){
		if(k&1){
			for(int i=1;i<=n;++i)ret[i]=p[ret[i]];
		}
		for(int i=1;i<=n;++i)t[i]=p[i];
		for(int i=1;i<=n;++i)p[i]=t[p[i]];
		k>>=1;
	}
}
int v[MAXN],ans[MAXN];
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)scanf("%d",a+i),d[i]=a[i]-a[i-1],v[i]=i;
	cin>>m>>k;
	for(int i=1;i<=m;++i){
		int x;
		scanf("%d",&x);
		swap(v[x],v[x+1]);
	}
        for(int i=1;i<=n;++i)p[v[i]]=i;
	ksm(k);
        ll sum=0;
	for(int i=1;i<=n;++i)ans[ret[i]]=i;
	for(int i=1;i<=n;++i)
		printf("%lld\n",sum+=d[ans[i]]);
	return 0;
}
