#include"bits/stdc++.h"


#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(ll x = (l);x<=(u);x++)
#define RREP(x,l,u) for(ll x = (l);x>=(u);x--)
#define mst(x,a) memset(x,a,sizeof(x))
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define se second
#define fi first
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define sz(x) ((int)x.size())
#define cl(x) x.clear()

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;

const int maxn = 300010;
const int mod = 1e9+7;
const double eps = 1e-6;
const double PI = acos(-1);

template<typename T> inline void read(T &x){
x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}

template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}
template<typename A,typename B> inline A fexp(A x,B p){A ans=1;for(;p;p>>=1,x=1LL*x*x%mod)if(p&1)ans=1LL*ans*x%mod;return ans;}
template<typename A,typename B> inline A fexp(A x,B p,A mo){A ans=1;for(;p;p>>=1,x=1LL*x*x%mo)if(p&1)ans=1LL*ans*x%mo;return ans;}

int n,m;

vector<int> has[maxn];

int sm[maxn*25],ls[maxn*25],rs[maxn*25],sz;

int rt[maxn];

int query(int x,int y,int l,int r,int pos){
	if(!pos)return 0;
	if(pos>=r)return sm[y]-sm[x];
	int M=l+r>>1;
	int ans=0;
	ans+=query(ls[x],ls[y],l,M,pos);
	if(pos>M)ans+=query(rs[x],rs[y],M+1,r,pos);
	return ans;
}

void update(int x,int &y,int l,int r,int pos){
	sm[y=++sz]=sm[x]+1;ls[y]=ls[x];rs[y]=rs[x];
	if(l==r)return;
	int M=l+r>>1;
	if(pos<=M)update(ls[x],ls[y],l,M,pos);else update(rs[x],rs[y],M+1,r,pos);
}

void Work(){
	REP(i,1,m){
		int ans=0;
		for(int j=i;j-i<=m;j+=i)
			ans+=query(rt[j-i],rt[min(m+1,j)-1],1,m,j-1);
		iout(n-ans);
	}
}

void Init(){
	read(n,m);
	REP(i,1,n){
		int x,y;
		read(x,y);
		has[x].PB(y);
	}
	REP(i,1,m){
		rt[i]=rt[i-1];
		for(auto x:has[i])update(rt[i],rt[i],1,m,x);
	}
}

int main(){
	Init();
	Work();
	return 0;
}
