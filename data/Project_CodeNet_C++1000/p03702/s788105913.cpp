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

int n,A,B,a[N]; ll b[N];

bool check(int mid) {
	for (int i=1;i<=n;++i) b[i]=a[i]-1ll*mid*B;
	ll r=mid;
	for (int i=1;i<=n;++i) {
		if (b[i]>0) r-=(b[i]-1)/(A-B)+1;
		if (r<0) return 0;
	}
	return 1;
}

int main() {
	n=read(),A=read(),B=read();
	for (int i=1;i<=n;++i) a[i]=read();
	int L=0,R=1e9;
	while (L<R) {
		int mid=(L+R)>>1;
		if (check(mid)) R=mid;
		else L=mid+1;
	}
	printf("%d\n",L);
	return 0;
}