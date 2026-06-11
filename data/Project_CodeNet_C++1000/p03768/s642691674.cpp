#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define F first
#define S second
#define random(x) (rand()%x)
const int maxn=100005,INF=0x3f3f3f3f,mod=1000000007;
struct QES{
	int v,d,c;
	QES(){}
	QES(int x,int y,int z){
		v=x;d=y;c=z;
	}
}qes[maxn];
int n,m,q,vis[maxn],col[maxn];
vi eg[maxn];

int dfs(QES nd){
	//printf("(%d %d %d)\n",nd.v,nd.d,nd.c);
	if(col[nd.v]==0) col[nd.v]=nd.c;
	if(nd.d==0){
		return 0;
	}
	for(int i=0;i<eg[nd.v].size();i++){
		if(vis[eg[nd.v][i]]<nd.d-1){
			vis[eg[nd.v][i]]=nd.d-1;
			dfs(QES(eg[nd.v][i],nd.d-1,nd.c));
		}
	}
}
int main(){
	int t1,t2;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&t1,&t2);
		eg[t1].push_back(t2);
		eg[t2].push_back(t1);
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d%d",&qes[i].v,&qes[i].d,&qes[i].c);
	}
	memset(vis,-1,sizeof(vis));
	for(int i=q-1;i>=0;i--){
		if(vis[qes[i].v]<qes[i].d){
			vis[qes[i].v]=qes[i].d;
			dfs(qes[i]);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",col[i]);
	}
	return 0;
}
