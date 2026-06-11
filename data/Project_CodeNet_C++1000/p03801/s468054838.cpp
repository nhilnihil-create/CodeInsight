#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define mem(x,v) memset(x,v,sizeof(x))
#define fi first
#define se second
#define debug(x) cout << #x" = " << x << endl;
#define pp(x,y) cout << "pp: " << x << " " << y << endl;
namespace IO{
	const int L=1<<15;char ibuf[L|1],*iS=ibuf,*iT=ibuf,obuf[L|1],*oS=obuf,*oT=obuf+L,c,st[66];int tp=0,f;
	inline char gc(){if(iS==iT) iT=(iS=ibuf)+fread(ibuf,sizeof(char),L,stdin);return (*iS++);}
	inline void flush(){fwrite(obuf,sizeof(char),oS-obuf,stdout);oS = obuf;}
	inline void pc(char c){*oS++=c;if(oS==oT) flush();}
	#define gc getchar
	#define pc putchar
	inline ll read(){ll x=0;f=1,c=gc();for(;!isdigit(c);c=gc())if(c=='-')f=-1;for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c&15);return x*f;}
	inline void write(ll x){if(!x) pc('0');if(x<0) pc('-'),x=-x;while(x) st[++tp]=x%10+'0',x/=10;while(tp) pc(st[tp--]);}
	inline void writeln(ll x){write(x);pc('\n');}
	inline void wri(ll x){write(x),pc(' ');}
	struct IOflusher{~IOflusher(){flush();}}_ioflusher_;
}using IO::read;using IO::write;using IO::writeln;using IO::wri;//using IO::gc;using IO::pc;
int n;
vector<pair<ll,ll> > v;
ll ans[100010];
int main(){
	n = read();
	Rep(i,1,n) v.push_back({read(),i});
	sort(v.begin(),v.end());reverse(v.begin(),v.end());
	v.push_back({0,1e9});
	ll mn=1e9;
	rep(i,0,n){
		mn=min(mn,v[i].se);
		ans[mn] += (i+1) * (v[i].fi-v[i+1].fi);
	}
	Rep(i,1,n) writeln(ans[i]);
	return 0;
}
