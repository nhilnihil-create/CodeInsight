#include <bits/stdc++.h>
#define pb push_back
#define cmin(a,b) (a>b?a=b:a)
#define cmax(a,b) (a<b?a=b:a)
#define mem(a,k) memset(a,k,sizeof(a))
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define fore(i,v) for(int i=g[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
using namespace std;

#define Pr(f,...) //fprintf(stderr,f,##__VA_ARGS__),fflush(stderr)

typedef long long ll;

template<typename T>
void read(T &x){
	x=0; 
	char c;
	for(c=getchar();!isdigit(c);c=getchar()); 
	for(;isdigit(c);c=getchar())x=x*10+c-'0'; 
}

const int N=1e5+50; 

int n,a[N],k,ans;
vector<int> g[N];

int dfs(int v,int p){
	int len=1;
	for(int d:g[v])if(d!=p){
		int w=dfs(d,v);
		if(v!=1&&w>=k)++ans,w=0;
		len=max(len,w+1);
	}
	Pr("dfs v=%d,len=%d\n",v,len); 
	return len;
}

int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	//freopen("dat.in","r",stdin);
	//freopen("my.out","w",stdout);
#endif
	read(n),read(k); 
	rep(i,1,n){
		read(a[i]); 
	}
	ans+=a[1]!=1;
	rep(i,2,n)g[a[i]].pb(i);
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}