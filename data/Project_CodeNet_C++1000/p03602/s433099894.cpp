#include<bits/stdc++.h>
#define maxn 305
#define inf 2e9
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define mm 1000000007
#define pii pair<int,int> 
#define ll long long
#define rep(i,l,r) for (int i=l;i<=r;i++)
#define down(i,l,r) for (int i=l;i>=r;i--)
#define clr(x,y) memset(x,y,sizeof(x))
#define low(x) x&(-x)
#define for_each(iter,container) for(typeof(container.begin()) iter=container.begin();iter!=container.end();++iter)
using namespace std;
ll read(){
	ll x=0,f=1; char ch=getchar();
	while (!isdigit(ch)){if (ch=='-') f=-1; ch=getchar();}
	while (isdigit(ch)){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
struct data{int obj,pre,c;}e[maxn*maxn];
int vis[maxn],gg[maxn][maxn],head[maxn];
ll a[maxn][maxn],c[maxn][maxn],ans;
int n,tot,sum;
void insert(int x,int y,ll c){
	e[++tot].obj=y; e[tot].pre=head[x]; e[tot].c=c;head[x]=tot;
}
void dfs(int u){
	vis[u]=1; sum++;
	for (int j=head[u];j;j=e[j].pre){
		int v=e[j].obj;
		if (!vis[v]) dfs(v);
	}
}
int main() {
	n=read();
	rep(i,1,n) rep(j,1,n) a[i][j]=read();
	rep(k,1,n) {
		rep(i,1,n) rep(j,1,n) if (i!=j&&i!=k&&j!=k&&a[i][k]+a[k][j]==a[i][j]) gg[i][j]=1;
	}
	rep(i,1,n) rep(j,1,n) if (i==j) c[i][j]=0; else c[i][j]=inf;
	rep(i,1,n) rep(j,i+1,n) 
		if (!gg[i][j]) insert(i,j,a[i][j]),insert(j,i,a[i][j]),ans+=a[i][j],c[i][j]=c[j][i]=a[i][j];
	dfs(1);
//	printf("%lld\n",ans);
	if (sum!=n) {puts("-1"); return 0;}
	rep(k,1,n) rep(i,1,n) rep(j,1,n) c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
	rep(i,1,n) rep(j,1,n) if (c[i][j]!=a[i][j]) {puts("-1"); return 0;}
	printf("%lld\n",ans);
	return 0;
}