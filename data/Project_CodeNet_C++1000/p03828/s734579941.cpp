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

const int N=1000+10;
const int mod=1e9+7;

int n,c[N];
void calc(int x) {
	for (int i=2;i*i<=x;++i)
		while (x%i==0) x/=i,++c[i];
	if (x>1) ++c[x];
}

int main() {
	n=read();
	for (int i=1;i<=n;++i) calc(i);
	int ans=1;
	for (int i=1;i<=n;++i) ans=1ll*ans*(c[i]+1)%mod;
	printf("%d\n",ans);
	return 0;
}