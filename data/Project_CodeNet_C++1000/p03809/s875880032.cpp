#include<bits/stdc++.h>
#define ll long long
#define ljc 998244353
using namespace std;
#define gc getchar
inline ll read(){
    register ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=gc();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}
    return (f==1)?x:-x;
}
struct edge{
	int to,nxt;
}g[1010101];
int indo[1010101],head[1010101],tot,a[1010101];
inline void made(int from,int to){
	g[++tot].to=to;g[tot].nxt=head[from];head[from]=tot;
	indo[to]++;
}
inline void fail(){
	puts("NO");exit(0);
}
int f[1010101],n;
void dfs(int u,int faa){
	if (indo[u]==1) return (void)(f[u]=a[u]);
	int sum=0,mx=0;
	for (int i=head[u];i;i=g[i].nxt){
		int v=g[i].to;
		if (v==faa) continue;
		dfs(v,u);
		if (mx<f[v]) mx=f[v];
		sum+=f[v];
	}
	f[u]=2*a[u]-sum;
	if (f[u]<0||sum<a[u]) fail();
	if (mx*2>sum){
		int tmp=sum-mx;
		if (tmp<sum-a[u]) fail();
	}
}
signed main(){
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	if (n==2){
		puts(a[1]==a[2]?"YES":"NO");
		return 0;
	}
	for (int i=1;i<n;i++){
		int x=read(),y=read();
		made(x,y);made(y,x);
	}
	int R;
	for (int i=1;i<=n;i++){
		if (indo[i]!=1){
			R=i;break;
		}
	}
	dfs(R,0);
	if (f[R]!=0) fail();
	puts("YES");
	return 0;
}

