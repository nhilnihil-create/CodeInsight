#include<bits/stdc++.h>
#define del(a,i) memset(a,i,sizeof(a))
#define ll long long
#define inl inline
#define il inl void
#define it inl int
#define ill inl ll
#define re register
#define ri re int
#define rl re ll
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define INF 0x3f3f3f3f
using namespace std;
template<class T>il read(T &x){
	int f=1;char k=getchar();x=0;
	for(;k>'9'||k<'0';k=getchar()) if(k=='-') f=-1;
	for(;k>='0'&&k<='9';k=getchar()) x=(x<<3)+(x<<1)+k-'0';
	x*=f;
}
template<class T>il _print(T x){
	if(x/10) _print(x/10);
	putchar(x%10+'0');
}
template<class T>il print(T x){
	if(x<0) putchar('-'),x=-x;
	_print(x);
}
ll mul(ll a,ll b,ll mod){long double c=1.;return (a*b-(ll)(c*a*b/mod)*mod)%mod;}
it qpow(int x,int m,int mod){
	int res=1,bas=x;
	while(m){
		if(m&1) res=(1ll*res*bas)%mod;
		bas=(1ll*bas*bas)%mod,m>>=1;
	}
	return res;
}
const int N = 1e5+5;
int n,val[N];
ll ans,abs_sum[N],sum[N];
char op[2];
vector<int> vec;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n),read(val[1]),sum[1]=val[1];
	for(ri i=2;i<=n;++i){
		scanf("%s",op),read(val[i]);
		if(op[0]=='-') vec.push_back(i),sum[i]=sum[i-1]-val[i];
		else sum[i]=sum[i-1]+val[i];
	}
	vec.push_back(n+1);
	for(ri i=1;i<=n;++i) abs_sum[i]=abs_sum[i-1]+val[i];
	if(vec.size()==1) return print(sum[n]),0;
	ans=LLONG_MIN;
	for(ri i=0;i<(int)vec.size()-1;++i){
		int x=vec[i],y=vec[i+1];
		ans=max(ans,sum[x-1]-(abs_sum[y-1]-abs_sum[x-1])+(abs_sum[n]-abs_sum[y-1]));
	}
	print(ans);
	return 0;
}