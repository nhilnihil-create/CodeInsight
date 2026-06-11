#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
using namespace std;

const int N=305;
const int M=200005;
const ll inf=1000000000000000ll;

struct E{
	int x,y,w;
	E(){}
	E(int x,int y,int w):x(x),y(y),w(w){}
}mem[M];
struct node{
	int to,w;
	node(){}
	node(int to,int w):to(to),w(w){}
};
int n,m,x,y,w,r1,r2;
ll ans;
int mp[N][N],f[N];
ll dis[N];
bool vis[N];
vector<node> lev[N];
queue<int> q;

bool cmp(E a,E b){
	return a.w<b.w;
}

int find(int k){
	if (f[k]!=k) f[k]=find(f[k]);
	return f[k];
}

void add(int x,int y,int w){
	lev[x].push_back(node(y,w));
	lev[y].push_back(node(x,w));
}

void bfs(){
	int j,k,u;
	memset(vis,0,sizeof(vis));
	for (j=1;j<=n;j++) dis[j]=inf;
	q.push(x); dis[x]=0;
	while (!q.empty()){
		k=q.front(); q.pop(); vis[k]=0;
		for (j=0;j<lev[k].size();j++){
			u=lev[k][j].to;
			if (dis[k]+lev[k][j].w<dis[u]){
				dis[u]=dis[k]+lev[k][j].w;
				if (!vis[u]){
					vis[u]=1; q.push(u);
				}
			}
		}
	}
}

int main(){
	int i,j;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		for (j=1;j<=n;j++){
			scanf("%d",&mp[i][j]);
			if (i==j||i>j) continue;
			mem[++m]=E(i,j,mp[i][j]);
		}
	sort(mem+1,mem+1+m,cmp);
	for (i=1;i<=n;i++) f[i]=i;
	for (i=1;i<=m;i++){
		x=mem[i].x; y=mem[i].y; w=mem[i].w;
		r1=find(x); r2=find(y);
		if (r1!=r2){
			f[r2]=r1;
			add(x,y,w); ans+=1ll*w;
			continue;
		}
		bfs();
		if (dis[y]==1ll*w) continue;
		if (dis[y]<1ll*w){
			printf("-1\n");
			return 0;
		}
		add(x,y,w); ans+=1ll*w;
	}
	printf("%lld\n",ans);
	return 0;
}