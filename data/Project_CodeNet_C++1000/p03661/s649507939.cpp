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

const int N=200000+10;

int n,a[N];
ll pre[N],suf[N];

int main() {
	n=read();
	for (int i=1;i<=n;++i) a[i]=read();
	for (int i=1;i<=n;++i) pre[i]=pre[i-1]+a[i];
	for (int i=n;i>=1;--i) suf[i]=suf[i+1]+a[i];
	ll ans=1e18;
	for (int i=1;i<n;++i) ans=min(ans,abs(pre[i]-suf[i+1]));
	printf("%lld\n",ans);
	return 0;
}