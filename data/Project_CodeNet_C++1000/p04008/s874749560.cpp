#include<bits/stdc++.h>
#define N 100100
using namespace std;
int n,k,ans;
int fa[N],rd[N];
int zx[N];
bool done[N];
void dfs(int p){
	done[p]=1;
	if(p!=1){
		zx[p]++;
		if(zx[p]==k&&fa[p]!=1) ans++,zx[p]=0;
		zx[fa[p]]=max(zx[fa[p]],zx[p]);
		rd[fa[p]]--;
		if(rd[fa[p]]==0) dfs(fa[p]);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&fa[i]);
		if(i!=1) rd[fa[i]]++;
	}
	if(fa[1]!=1) ans++;
	for(int i=2;i<=n;i++){
		if(!rd[i]&&!done[i]){
			dfs(i);
		}
	}
	printf("%d\n",ans);
	return 0;
}