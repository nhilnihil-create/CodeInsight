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
const int mod=1e9+7;

int n,m,x[N],y[N];

int main() {
	n=read(),m=read();
	for (int i=1;i<=n;++i) x[i]=read();
	for (int i=1;i<=m;++i) y[i]=read();
	int sx=0,sy=0;
	for (int i=1;i<n;++i) sx=(sx+1ll*i*(n-i)%mod*(x[i+1]-x[i]))%mod;
	for (int i=1;i<m;++i) sy=(sy+1ll*i*(m-i)%mod*(y[i+1]-y[i]))%mod;
	printf("%d\n",1ll*sx*sy%mod);
	return 0;
}