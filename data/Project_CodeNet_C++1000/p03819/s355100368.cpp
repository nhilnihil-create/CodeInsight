#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define re(i,a,b) for(int i=(a);i<(b);i++)
#define repd(i,a,b) for(int i=(a);i>=(b);i--)
#define run(v) for(int k=head[v];k;k=e[k].ne)
#define v e[k].t
#define clr(a) memset(a,0,sizeof(a));
#define il inline
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back 
#define w1 first
#define w2 second
#define adm(a,b,c) {a=a+b;if(a>=c)a-=c;else if(a<0)a+=c;}
typedef long long ll;typedef long double ld;typedef unsigned long long ull;
typedef pair<ll,ll> pa;
const int N=5e5+5,M=1e7+5,INF=1e9,mod=1e9+7;
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
il void gen(){freopen("data.in","w",stdout);}
int n,m,bit[N];
struct data{int l,r,len;}a[N];
il bool cmp(data a,data b){return a.len<b.len;}
void add(int x,int y){for(;x<=m;x+=x&(-x))bit[x]+=y;}
int sum(int x){int res=0;for(;x;x-=x&(-x))res+=bit[x];return res;}
int main(){
	read(n,m);
	rep(i,1,n)read(a[i].l,a[i].r),a[i].len=a[i].r-a[i].l+1;
	sort(a+1,a+1+n,cmp);
	int pt=1;
	rep(d,1,m){
		while(pt<=n&&a[pt].len<d){
			add(a[pt].l,1);
			add(a[pt].r+1,-1);		
			pt++;
		}
		int ans=n-pt+1;
		for(int cur=d;cur<=m;cur+=d)ans+=sum(cur);
		cout<<ans<<endl;
	}
}