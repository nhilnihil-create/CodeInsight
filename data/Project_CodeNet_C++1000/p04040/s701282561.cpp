#include <bits/stdc++.h>
using namespace std;

const int N=1e6+50, mod=1e9+7;
inline int add(int x,int y) {return (x+y>=mod) ? (x+y-mod) : (x+y);}
inline int dec(int x,int y) {return (x-y<0) ? (x-y+mod) : (x-y);}
inline int mul(int x,int y) {return (long long)x*y%mod;}
inline int power(int a,int b,int rs=1) {for(;b;b>>=1,a=mul(a,a)) if(b&1) rs=mul(rs,a); return rs;}
inline int inv(int a) {return power(a,mod-2);}

struct combin {
	int fac[N],ifac[N];
	combin() {
		fac[0]=1;
		for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
		ifac[0]=ifac[1]=1;
		for(int i=2;i<N;i++) ifac[i]=mul(mod-mod/i,ifac[mod%i]);
		for(int i=2;i<N;i++) ifac[i]=mul(ifac[i-1],ifac[i]);
	}
	inline int C(int a,int b) {return mul(fac[a],mul(ifac[b],ifac[a-b]));}
} C;
#define x1 dqoaspjdioq
#define x2 dnasuihquih
#define y1 adsjiohejqu
#define y2 dnasuigqyuw
inline int path(int x1,int y1,int x2,int y2) {
	return C.C(x2-x1+y2-y1,x2-x1);
}
int n,m,a,b;
int main() {
	cin>>n>>m>>a>>b; 
	int ans=path(1,1,n,m);
	for(int i=1;i<=b;i++)
		ans=dec(ans,mul(path(1,1,n-a,i),path(n-a+1,i,n,m)));
	cout<<ans<<'\n';
}