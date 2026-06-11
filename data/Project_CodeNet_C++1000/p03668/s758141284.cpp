#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define re(i,a,b) for(int i=(a);i<(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define run(a) for(int k=head[a];k;k=e[k].ne)
#define clr(a) memset(a,0,sizeof(a));
#define il inline
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back 
#define w1 first
#define w2 second
#define adm(a,b,c) {a=a+b;if(a>=c)a-=c;else if(a<0)a+=c;}
typedef double db;
typedef long long ll;typedef long double ld;typedef unsigned long long ull;
typedef pair<ll,ll> pa;
const int N=1e6+5,M=5e3+5,INF=1e9,mod=998244353;
const ll linf=1e18;const double eps=1e-8,pi=acos(-1);
il int gmin(int &a,int b){if(a>b)a=b;}il ll gmin(ll &a,ll b){if(a>b)a=b;}il int gmax(int &a,int b){if(a<b)a=b;}il ll gmax(ll &a,ll b){if(a<b)a=b;}
il void read(ll&x){ll f=1,t=0;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){t=t*10+ch-'0';ch=getchar();}x=t*f;}il ll read(ll&x,ll&y){read(x);read(y);}
il void read(int&x){int f=1,t=0;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){t=t*10+ch-'0';ch=getchar();}x=t*f;}il int read(int&x,int&y){read(x);read(y);}
il void read(int&a,int&b,int&c){read(a);read(b);read(c);}il void read(ll&a,ll&b,ll&c){read(a);read(b);read(c);}
il int read(){int x;read(x);return x;}
il ll qpow(ll a,ll b,ll p){ll ret=1;for(;b;b>>=1,a=a*a%p)if(b&1)ret=ret*a%p;return ret;}il ll qpow(ll a,ll b){ll ret=1;for(;b;b>>=1,a=a*a%mod)if(b&1)ret=ret*a%mod;return ret;}
il ll qmul(ll a,ll b,ll p){ll ret=0;for(;b;b>>=1,a=(a<<1)%p)if(b&1)adm(ret,a,p);return ret;}il ll qmul(ll a,ll b){ll ret=0;for(;b;b>>=1,a=(a<<1)%mod)if(b&1)adm(ret,a,mod);return ret;}
il void judge(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);}
int n;
vector<int>e[N];
int dfs(int x,int f){
	int res=0;
	re(i,0,e[x].size())if(e[x][i]!=f)res^=dfs(e[x][i],x)+1;
	return res;
}
int main(){
	read(n);re(i,1,n){
		int x,y;read(x,y);
		e[x].pb(y);e[y].pb(x);
	}
	cout<<(dfs(1,0)?"Alice":"Bob");
}