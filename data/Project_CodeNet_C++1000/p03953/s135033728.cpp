#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+10;
int n,m,a[maxn],x[maxn],d[maxn],p[maxn],fa[63][maxn];
ll k,ans[maxn];

int main(){
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	cin>>m>>k;
	for(int i=1;i<=m;++i)
		cin>>x[i];
	for(int i=1;i<n;++i)
		d[i]=a[i+1]-a[i];
	for(int i=1;i<n;++i)
		p[i]=i;
	for(int i=1;i<=m;++i)
		swap(p[x[i]-1],p[x[i]]);
	for(int i=1;i<n;++i)
		fa[0][i]=p[i];
	for(int i=1;i<63;++i)
		for(int j=1;j<n;++j)
			fa[i][j]=fa[i-1][fa[i-1][j]];
	ans[1]=a[1];
	for(int i=1;i<n;++i){
		int pos=i;
		for(int j=62;~j;--j)
			if(k>>j&1ll)
				pos=fa[j][pos];
		ans[i+1]=ans[i]+d[pos];
	}
	for(int i=1;i<=n;++i)
		printf("%lld\n",ans[i]);
	return 0;
}