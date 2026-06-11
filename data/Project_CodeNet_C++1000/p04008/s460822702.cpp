#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,k,fa[N];
int ans=0,Maxd[N];
vector <int> e[N];
void solve(int x){
	Maxd[x]=0;
	for (auto y : e[x]){
		solve(y);
		Maxd[x]=max(Maxd[x],Maxd[y]+1);
	}
	if (Maxd[x]==k-1&&fa[x]!=1)
		ans++,Maxd[x]=-1;
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		e[i].clear();
	for (int i=1;i<=n;i++){
		scanf("%d",&fa[i]);
		if (i>1)
			e[fa[i]].push_back(i);
	}
	if (fa[1]!=1)
		fa[1]=1,ans++;
	solve(1);
	printf("%d",ans);
	return 0;
}