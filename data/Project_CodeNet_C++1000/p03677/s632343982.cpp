// ====================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ====================================
#include <bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout)
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;

int read() {
	int X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

const int N=100000+10;

int n,m,a[N]; ll x[N];

void add(int l,int r,int s,int d) {
	int e=s+(r-l)*d;
	x[l]+=s,x[l+1]+=d-s;
	x[r+1]-=d+e,x[r+2]+=e;
}

int main() {
	n=read(),m=read();
	for (int i=1;i<=n;++i) a[i]=read();
	ll sum=0;
	for (int i=2;i<=n;++i) {
		if (a[i-1]<=a[i]) {
			sum+=a[i]-a[i-1];
			add(a[i-1]+1,a[i],0,1);
		} else {
			sum+=m-a[i-1]+a[i];
			add(a[i-1]+1,m,0,1),add(1,a[i],m-a[i-1],1);
		}
	}
	for (int i=1;i<=m;++i) x[i]+=x[i-1];
	for (int i=1;i<=m;++i) x[i]+=x[i-1];
	ll mx=0;
	for (int i=1;i<=m;++i) mx=max(mx,x[i]);
	printf("%lld\n",sum-mx);
	return 0;
}