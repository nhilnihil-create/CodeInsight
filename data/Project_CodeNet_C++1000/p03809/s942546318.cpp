#include <bits/stdc++.h>
#define pb push_back
#define cmin(a,b) (a>b?a=b:a)
#define cmax(a,b) (a<b?a=b:a)
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define fore(i,v) for(int i=g[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
using namespace std;

#define Pr(f,...) //fprintf(stderr,f,##__VA_ARGS__),fflush(stderr)

const int N=5e5+50; 

void read(int &x){
	x=0; 
	char c=getchar(); 
	for(;!isdigit(c);c=getchar()); 
	for(;isdigit(c);c=getchar())x=x*10+c-'0'; 
}

vector<int> g[N]; 
int n,a[N],root,fail,deg[N]; 

int dfs(int v,int p){
	if(deg[v]==1)return a[v];
	int sum=0,mxr=0;
	for(int d:g[v])if(d!=p){
		int req=dfs(d,v); 
		cmax(mxr,req); 
		sum+=req;
	}	
	int tim=mxr>sum/2?(sum-mxr):(sum/2); 
	//0<=x<=tim:x+(sum-x*2)==a[v]
	Pr("v=%d,p=%d,tim=%d,sum=%d,mxr=%d\n",v,p,tim,sum,mxr); 
	int x=sum-a[v];
	if(x<0||x>tim)fail=true;
	return sum-x*2;
}

int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	//freopen("dat.in","r",stdin);
	//freopen("my.out","w",stdout);
#endif
	read(n); 
	rep(i,1,n)read(a[i]); 
	rep(i,1,n-1){
		int u,v; 
		read(u),read(v); 
		g[u].pb(v),g[v].pb(u);
		++deg[u],++deg[v];
	}
	if(n==2)fail=a[1]!=a[2];
	rep(i,1,n)if(deg[i]>1)root=i;
	int res=dfs(root,0); 
	if(res!=0||fail)puts("NO");else puts("YES"); 
	return 0;
}