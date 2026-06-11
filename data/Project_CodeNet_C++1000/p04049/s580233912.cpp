#include<bits/stdc++.h>
using namespace std;
#define IL inline
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define repd(i,j,k) for(int i=j;i>=k;--i)
#define pb push_back
#define db double
#define mp make_pair
#define mp3(a,b,c) mp(mp(a,b),c)
#define pii pair<int,int>
#define piii pair<pii,int>
#define fr first
#define se second
#define ll long long
#define ull unsigned long long
#define pbc(x) __builtin_popcount(x)
#define clr(x) memset(x,0,sizeof x)
#define SIZE(x) (int)(x.size())
const int mod=1e9+7;
IL int pls(int x,int y){x+=y;return x>=mod?x-mod:x;}
IL int dec(int x,int y){x-=y;return x<0?x+mod:x;}
IL int mul(int x,int y){return 1ll*x*y%mod;}
IL int mul(int x,int y,int z){return mul(mul(x,y),z);}
IL int mul(int x,int y,int z,int p){return mul(mul(x,y),mul(z,p));}
IL void add(int &x,int y){x+=y;x=(x>=mod)?x-mod:x;}
IL int fpw(int x,int y,int r=1){for(;y;y>>=1,x=mul(x,x))if(y&1)r=mul(r,x);return r;}
IL int inv(int x){return fpw(x,mod-2);}
IL int gi(){int x;int _w=scanf("%d",&x);return x;}
IL void gi(int &x){int _w=scanf("%d",&x);}
IL void write(int x){printf("%d\n",x);}
void chkmax(int &x,int y){x=(x>y)?x:y;}
void chkmin(int &x,int y){x=(x<y)?x:y;}
const int INF=0x3f3f3f3f;
template<typename T>IL void debug(T x){cerr<<x;return;}
/* --------------------------------------------------------------------------------------------------------- */
const int maxn=2005;
int n,k;
vector<int>e[maxn];
namespace sub1{
	int dep[maxn];
	IL bool check(){
		return (!(k&1));
	}
	void dfs(int x,int fa){
		for(int v:e[x])if(v!=fa)dep[v]=dep[x]+1,dfs(v,x);
	}
	IL void work(){
		int ans=n;
		rep(i,1,n){
			rep(j,1,n)dep[j]=0;
			dfs(i,0);
			int del=0;
			rep(j,1,n){
				if(dep[j]>k/2)del++;
			}
			ans=min(ans,del);
		}
		printf("%d\n",ans);
	}
}
namespace sub2{
	pii edge[maxn];
	int dep[maxn];
	IL bool check(){
		return k&1;
	}
	void dfs(int x,int fa){
		for(int v:e[x])if(v!=fa)dep[v]=dep[x]+1,dfs(v,x);
	}
	IL void work(){
		int ans=n;
		rep(i,1,n-1){
			int del=0;
			rep(j,1,n)dep[j]=0;
			dfs(edge[i].fr,edge[i].se);
			dfs(edge[i].se,edge[i].fr);
			rep(j,1,n)if(dep[j]>k/2)del++;
			ans=min(ans,del);
		}
		printf("%d\n",ans);
	}
}
int main(){
#ifdef LOCAL
	freopen("/home/noilinux/Desktop/input.txt","r",stdin);
#endif
	n=gi(),k=gi();
	rep(i,1,n-1){
		int x=gi(),y=gi();
		e[x].pb(y);e[y].pb(x);
		sub2::edge[i]={x,y};
	}
	if(sub1::check())sub1::work();else sub2::work();
	return 0;
}