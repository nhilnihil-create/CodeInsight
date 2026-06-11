#include<cstdio>
#include<iostream>
using namespace std;
int beg[100100],nex[400100],tto[400100],e;
void putin(int s,int t){
	tto[++e]=t;
	nex[e]=beg[s];
	beg[s]=e;
}
bool vis[100100];
int c[100100];
int dfs(int u){
	if(vis[u]) return 0;
	vis[u]=1;
	int res=1;
	for(int i=beg[u];i;i=nex[i])
		res+=dfs(tto[i]);
	return res;
}
bool color(int u,int co){
	c[u]=co;
	for(int i=beg[u];i;i=nex[i]){
		if(!c[tto[i]]){
			if(!color(tto[i],3-c[u]))
				return 0;
		}
		if(c[tto[i]]==c[u]) return 0;
	}
	return 1;
}
long long getsum(long long x){
	return x*(x-1)/2;
}
int main(){
//	freopen("C.in","r",stdin);
//	freopen("C.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int s,t;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&s,&t);
		putin(s,t);
		putin(t,s);
	}
	int cnta=0,cntb=0,cntc=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(dfs(i)==1)
				cntc++;
			else{
				if(color(i,1))
					cnta++;
				else
					cntb++;
			}
			
		}
	}
	long long ans=2*cnta+cntb;
	ans=ans+getsum(cnta)*4+getsum(cntb)*2;
	ans=ans+cnta*(long long)cntb*2;
	ans=ans+cntc*(long long)n*2-cntc*(long long)cntc;
	printf("%lld\n",ans);
	return 0;
}
