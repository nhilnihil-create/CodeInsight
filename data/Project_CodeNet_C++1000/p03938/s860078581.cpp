// ====================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ====================================
#include <bits/stdc++.h>
#define file(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout)
using namespace std;
typedef long long ll;

int read() {
	int X=0,w=1; char c=getchar();
	while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
	while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
	return X*w;
}

const int N=20000+10;

int n,p[N],a[N],b[N];

int main() {
	n=read();
	for (int i=1;i<=n;++i) p[i]=read();
	for (int i=1;i<=n;++i) a[i]=a[i-1]+50000;
	for (int i=n;i>=1;--i) b[i]=b[i+1]+50000;
	for (int i=1;i<=n;++i) a[p[i]]-=n-i;
	for (int i=1;i<=n;++i) printf("%d ",a[i]); puts("");
	for (int i=1;i<=n;++i) printf("%d ",b[i]); puts("");
	return 0;
}