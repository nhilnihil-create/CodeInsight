#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<queue>
using namespace std;

const int N=1000005;
const int M=N<<1;

struct E{
	int to,next;
}mem[M];
int n,m,x,y,k,u,num,I,P,Q,sz;
bool tag;
int head[N],dis[N];
bool vis[N];
queue<int> q;

void add(int x,int y){
	num++;
	mem[num].to=y; mem[num].next=head[x];
	head[x]=num;
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	for (int i=1;i<=n;i++){
		if (vis[i]) continue;
		while (!q.empty()) q.pop();
		sz=1; tag=1;
		q.push(i); vis[i]=1; dis[i]=0;
		while (!q.empty()){
			k=q.front(); q.pop();
			for (int j=head[k];j;j=mem[j].next){
				u=mem[j].to;
				if (!vis[u]){
					vis[u]=1;
					sz++;
					q.push(u);
					dis[u]=dis[k]+1;
				}
				else{
					if ((dis[k]-dis[u])%2==0) tag=0;
				}
			}
		}
		if (sz==1) I++;
		else{
			if (tag) Q++;
			else P++;
		}
	}
	printf("%lld\n",2ll*I*n-1ll*I*I+1ll*P*P+2ll*P*Q+2ll*Q*Q);
	return 0;
}