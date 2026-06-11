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

int main() {
	int n=read(); ll x=read(),y=read();
	for (int i=2;i<=n;++i) {
		int a=read(),b=read();
		ll d=max(x/a+(x%a!=0),y/b+(y%b!=0));
		x=a*d,y=b*d;
	}
	printf("%lld\n",x+y);
	return 0;
}