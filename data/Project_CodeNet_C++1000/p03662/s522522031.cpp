#include<cstdio>
#include<vector>
using namespace std;
int n;
const int MAXN=1e5+5;
vector<int>neigh[MAXN];
int cnt[MAXN],L[MAXN],P[MAXN];
void Traverse(int v){
	cnt[v]=1;
	for(int i=0;i<neigh[v].size();i++){
		int u=neigh[v][i];
		if(P[v]==u)continue;
		L[u]=L[v]+1;P[u]=v;
		Traverse(u);
		cnt[v]+=cnt[u];
	}
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int a,b;scanf("%d%d",&a,&b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(1);
	int up=(L[n]-1)/2;
	int v=n;
	while(up--)v=P[v];
	if(cnt[v]>=n-cnt[v])printf("Snuke\n");
	else printf("Fennec\n");
	return 0;
}