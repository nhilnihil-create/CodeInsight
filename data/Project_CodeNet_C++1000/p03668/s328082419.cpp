#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;

namespace INPUT{
	const int L=1<<15;
	char _buf[L],*S,*T,c;
	char _gc(){
		if(S==T){
			T=(S=_buf)+fread(_buf,1,L,stdin);
			if(S==T) return EOF;
		}
		return *S++;
	}
	void readi(int &X){
		for(c=_gc();c<'0'||c>'9';c=_gc());X=c&15;
		for(c=_gc();c>='0'&&c<='9';X=X*10+(c&15),c=_gc());
	}
}
using INPUT::readi;

const int Maxn=1E5+5;

int N;
struct E{
	int v,nxt;
}adj[Maxn<<1];
int hed[Maxn],TE;

void addedge(int u,int v){
adj[++TE].v=v,adj[TE].nxt=hed[u],hed[u]=TE;}

int Dfs(int u,int Fa){
	int Val=0;
	for(int k=hed[u];~k;k=adj[k].nxt)
		if(adj[k].v!=Fa) Val^=(Dfs(adj[k].v,u)+1);
	return Val;
}

int main(){
	readi(N);
	memset(hed,-1,sizeof(hed));
	for(int u,v,i=1;i<N;++i)
		readi(u),readi(v),
		addedge(u,v),addedge(v,u);
	if(Dfs(1,0)==0) puts("Bob"); else puts("Alice");
	return 0;
}
