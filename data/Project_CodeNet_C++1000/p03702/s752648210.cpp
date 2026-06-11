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
int n,m,q;
ll A,B,a[MAXN],b[MAXN];
bool check(ll x){
	ll num=0;
	FOR(i,1,n)
	if (a[i]>x*B) {
		ll y=a[i]-x*B;
		num+=(y+A-1)/A;
		if (num>x) return false;
	}
	return true;
}
int main(){
	n=read();
	A=read(),B=read();
	A-=B;
	FOR(i,1,n) a[i]=read();
	int l=0,r=1e9+1,mid;
	while (l+1<r) {
		mid=(l+r)/2;
		if (check(mid)) r=mid; else l=mid;
	}
	printf("%d\n",r);
	
	return 0;
}

/*
*/
