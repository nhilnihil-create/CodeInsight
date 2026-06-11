#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
template<typename T>inline bool chkmin(T &x,T y){return (y<x)?(x=y,1):0;}
template<typename T>inline bool chkmax(T &x,T y){return (y>x)?(x=y,1):0;}
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
const int maxn=1e5+10;
int Begin[maxn],Next[maxn],to[maxn],e;
int num[maxn],tmp,f[maxn];
inline void add_edge(int x,int y){
	to[++e]=y;
	Next[e]=Begin[x];
	Begin[x]=e;
}
void dfs(int x){
	for(int i=Begin[x];i;i=Next[i]) dfs(to[i]);
	tmp=0;
	for(int i=Begin[x];i;i=Next[i]) num[++tmp]=f[to[i]];
	sort(num+1,num+tmp+1);
	REP(i,1,tmp) chkmax(f[x],num[i]+tmp-i+1);
}
int main(){
	int n=read();
	REP(i,2,n){
		int x=read();
		add_edge(x,i);
	}
	dfs(1);
	printf("%d\n",f[1]);
	return 0;
}
