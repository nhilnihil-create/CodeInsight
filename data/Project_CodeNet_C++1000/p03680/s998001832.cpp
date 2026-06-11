#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> P; 

const int maxn = 100010;

int n,m,s,u,v;
int dis[maxn],vis[maxn];

priority_queue<P,vector<P>,greater<P> > q;

int h[maxn],siz;
struct E{
	int to , next;
	ll cost;
}e[maxn*2];
void add(int u,int v,ll w){
	e[++siz].to = v;
	e[siz].cost = w;
	e[siz].next = h[u];
	h[u]=siz;
}

void dij(){
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	q.push(P(0,1));
	
	while(!q.empty()){
		int u = q.top().second; q.pop();
		
		if(vis[u]) continue;
		vis[u]=1;
		
		for(int i = h[u];i != -1;i = e[i].next){
			int v = e[i].to;
			if(dis[v] > dis[u] + e[i].cost){
				dis[v] = dis[u] + e[i].cost;
				q.push(P(dis[v],v));
			}
		}
	}
	
}

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	memset(h,-1,sizeof(h));
	memset(vis,0,sizeof(vis));
	n=read();
	for(int i = 1;i <= n;i++){
		v=read();
		add(i,v,1);
	}

	dij();

	if((h[2] == -1)||vis[2] == 0){
		printf("-1\n");
		return 0; 
	}
	
	printf("%d\n",dis[2]);
	
	return 0;
}