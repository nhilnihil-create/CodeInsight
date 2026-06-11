#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<=(b);++i)
#define ROF(i,a,b) for (int i=(a);i>=(b);--i)
typedef long long ll;
inline int read() {
	int x=0,s=1; char ch=getchar();
	while (ch<'0'||ch>'9') { if (ch=='-') s=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return s*x;
}

const int MAXN=400005,Mo=1000000007;
multiset<int> S;
ll f[MAXN],g[MAXN];
int n,m,q,a[MAXN],b[MAXN];
int main(){
	n=read();
	FOR(i,1,n*3) a[i]=read();
	S.clear();
	ll sum=0;
	FOR(i,1,n) sum+=a[i],S.insert(a[i]);
	f[0]=sum;
	FOR(i,n+1,n*2) {
		sum+=a[i]; S.insert(a[i]);
		auto x=S.begin();
		sum-=*x; S.erase(x);
		f[i-n]=sum;
	}
	sum=0,S.clear();
	FOR(i,1,n) sum+=a[i+n*2],S.insert(-a[i+n*2]);
	g[0]=sum;
	ROF(i,n*2,n+1) {
		sum+=a[i]; S.insert(-a[i]);
		auto x=S.begin();
		sum+=*x; S.erase(x);
		g[n*2+1-i]=sum;
	}
	ll ans=-1e18;
	FOR(i,0,n) ans=max(ans,f[i]-g[n-i]);
	cout<<ans<<endl;
	
	return 0;
}

/*
*/
