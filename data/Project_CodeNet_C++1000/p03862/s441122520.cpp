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

int n,x,a[N];

int main() {
	n=read(),x=read();
	for (int i=1;i<=n;++i) a[i]=read();
	ll ans=0;
	for (int i=2;i<=n;++i) {
		if (a[i-1]+a[i]>=x) {
			int dlt=a[i-1]+a[i]-x; ans+=dlt;
			if (a[i]>=dlt) a[i]-=dlt;
			else a[i]=0,a[i-1]-=dlt-a[i];
		}
	}
	printf("%lld\n",ans);
	return 0;
}