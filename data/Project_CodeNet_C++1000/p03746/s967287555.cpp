#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define lo long long 
#define inf 1000000000
#define md 1000000007
#define pb push_back
#define li 100005
using namespace std;
int n,m,x,y,deg[li],vis[li],tp[li];
vector<int> v[li];
vector<int> yol;
pair<int,int> A[li];
void dfs(int node,int ata){
	vis[node]=1;
	yol.pb(node);
	deg[node]--;
	int mn=inf,tut=-1;
	for(int i=0;i<(int)v[node].size();i++){
		int go=v[node][i];
		if(go!=ata && vis[go]==0){
			if(deg[go]<mn){
				mn=deg[go];
				tut=go;
			}
		}
	}
	if(tut!=-1) dfs(tut,node);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		v[x].pb(y);
		v[y].pb(x);
		deg[x]++;
		deg[y]++;
	}
	for(int i=1;i<=n;i++){
		A[i]=mp(deg[i],i);
	}
	sort(A+1,A+n+1);
	for(int i=1;i<=n;i++){
		yol.clear();
		memset(vis,0,sizeof(vis));
		memset(tp,0,sizeof(tp));
		dfs(A[i].se,-1);
		for(int j=0;j<(int)yol.size();j++){
			tp[yol[j]]=1;
		}
		int flag=0;
		if((int)yol.size()<=1) continue;
		for(int j=0;j<(int)v[yol[0]].size();j++){
			if(tp[v[yol[0]][j]]==0){
				flag=1;
				break;
			}
		}
		if(flag==1) continue;
		flag=0;
		for(int j=0;j<(int)v[yol[(int)yol.size()-1]].size();j++){
			if(tp[v[yol[(int)yol.size()-1]][j]]==0){
				flag=1;
				break;
			}
		}
		if(flag==1) continue;
		flag=0;
		printf("%d\n",(int)yol.size());
		for(int j=0;j<(int)yol.size();j++) printf("%d ",yol[j]);
		return 0;
	}
	return 0;
}
