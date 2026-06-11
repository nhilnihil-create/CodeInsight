#include <bits/stdc++.h>
using namespace std;
const int N=303;
int n,m,a[N][N];
int ans=1e9;
int res[N],vis[N];
int cac() {
	memset(res,0,sizeof(res));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vis[a[i][j]]==1)continue;
			res[a[i][j]]++; break;
		}
	}
	int mx=0,mxpos=1;
	for(int i=1;i<=m;i++){
		if(res[i]>=mx){
			mx=res[i]; mxpos=i;
		}
	}
	//printf("mxpos=%d, mx=%d\n", mxpos,mx);
	vis[mxpos]=1;
	return mx;
}
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);	
	for(int i=1;i<=m;i++) ans=min(ans,cac());
	cout<<ans<<endl;
}