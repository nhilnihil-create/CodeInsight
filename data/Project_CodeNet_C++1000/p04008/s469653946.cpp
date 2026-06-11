/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#include<bits/stdc++.h>
#define ll long long
#define N 500005
#define inf 1000000005
#define mod 1000000007
#define put putchar('\n')
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,t) for (int i=head[t];i;i=Next[i])
#define sqr(x) ((x)*(x))
#define re register
#define mp make_pair
#define fi first
#define se second
#define int ll
using namespace std;
inline int read(){char c=getchar();int tot=1;while ((c<'0'|| c>'9')&&c!='-') c=getchar();if (c=='-'){tot=-1;c=getchar();}
int sum=0;while (c>='0'&&c<='9'){sum=sum*10+c-'0';c=getchar();}return sum*tot;}
inline void wr(int x){if (x<0) {putchar('-');wr(-x);return;}if(x>=10)wr(x/10);putchar(x%10+'0');}
inline void wrn(int x){wr(x);put;}inline void wri(int x){wr(x);putchar(' ');}
inline void wrn(int x,int y){wri(x);wrn(y);}inline void wrn(int a,int b,int c){wri(a);wrn(b,c);}
int n,m,k,dis[N],ans,a[N],fa[N];
int nedge,Next[N*2],head[N],to[N*2];
#define V to[i]
void add(int a,int b){
	Next[++nedge]=head[a];head[a]=nedge;to[nedge]=b;
}
void dfs(int x){
	dis[x]=1;
	go(i,x){
		fa[V]=x;dfs(V);dis[x]=max(dis[x],dis[V]+1);
	}
	if (dis[x]==k&&fa[x]!=1&&x!=1) ans++,dis[x]=0;
}
signed main(){
	n=read();k=read();
	F(i,1,n) a[i]=read();
	if (a[1]!=1) ans++;
	F(i,2,n) add(a[i],i);
	dfs(1);
	wrn(ans);
	return 0;
}