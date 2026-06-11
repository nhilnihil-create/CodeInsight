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

int n,a[N];

int main() {
	n=read();
	for (int i=1;i<=n;++i) a[i]=read();
	ll ans1=0,ans2=0,sum=0;
	for (int i=1;i<=n;++i) {
		if (i&1) {
			if (sum+a[i]>0) sum+=a[i];
			else ans1+=1-(sum+a[i]),sum=1;
		} else {
			if (sum+a[i]<0) sum+=a[i];
			else ans1+=(sum+a[i])+1,sum=-1;
		}
	}
	sum=0;
	for (int i=1;i<=n;++i) {
		if (i&1) {
			if (sum+a[i]<0) sum+=a[i];
			else ans2+=(sum+a[i])+1,sum=-1;
		} else {
			if (sum+a[i]>0) sum+=a[i];
			else ans2+=1-(sum+a[i]),sum=1;
		}
	}
	printf("%lld\n",min(ans1,ans2));
	return 0;
}