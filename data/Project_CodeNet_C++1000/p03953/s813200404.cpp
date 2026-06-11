#include<bits/stdc++.h>
namespace my_std{
	using namespace std;
	#define reg register
	#define Rint register int
	#define FOR(i,a,b) for(register int i=(a);i<=(b);++i)
	#define ROF(i,a,b) for(register int i=(a);i>=(b);--i)
	#define FORit(templ,arr,i,a,b) for(register templ *i=(arr)+(a);i!=(arr)+(b)+1;++i)
	#define ROFit(templ,arr,i,a,b) for(register templ *i=(arr)+(a);i!=(arr)+(b)-1;--i)
	#define GO(x,p,e,i,v) for(register int i=p[x].head,v;i;i=e[i].link)
	#define MEM(x,v) memset(x,v,sizeof(x))
	#define fir first
	#define sec second
	#define pq priority_queue
	#define PII pair<int,int>
	#define MP make_pair
	typedef long long LL;
	typedef double DB;
	inline int read(){
		int ans=0,f=1;char c=getchar();
		while(!isdigit(c)){ f^=(c=='-'); c=getchar(); }
		for(;isdigit(c);c=getchar()) ans=(ans<<1)+(ans<<3)+(c^48); return f?ans:-ans;
	}
	const int mod = 998244353 , N = 100010;
	inline void inc(int &x,const int &y){ x+=y; if(x>=mod) x-=mod; }
	inline int ksm(int x,LL y){ int res=1; for(;y;y>>=1,x=1ll*x*x%mod) if(y&1) res=1ll*res*x%mod; return res;}
	inline int gcd(int x,int y){ if(x<y) swap(x,y); return y?gcd(y,x%y):x; }
	#define FILE(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
}
using namespace my_std;

int n,m,x[N],pos[N],vis[N];
LL k , ans[N];
int stk[N] , top;

int main(){
	n = read();
	FOR(i,1,n) x[i] = read() , pos[i] = i;
	ROF(i,n,1) x[i] -= x[i - 1];
	m = read() , scanf("%lld",&k);
	Rint xx;
	FOR(i,1,m) xx = read() , swap(pos[xx] , pos[xx + 1]);
	FOR(i,1,n){
		if(!vis[i]){
			for(Rint j = i;!vis[j];j = pos[j]) vis[stk[top++] = j] = 1;
			FOR(j,0,top - 1) ans[stk[j]] = x[stk[(j + k) % top]];
			top = 0;
		}
	}
	FOR(i,1,n) ans[i] += ans[i - 1] , printf("%lld.0\n",ans[i]);
	return 0;
}//神luogu怎么知道我刚做了这个啊啊啊啊