#include <bits/stdc++.h>
#define ll long long
#define lf double
#define E complex<lf>
#define inf 0x3f3f3f3f
#define eps 1e-8
#define pa pair<int,int>
#define pb push_back
#define ms(x,y) memset(x,y,sizeof(x))
#define l(x) (x<<1)
#define r(x) (x<<1|1)
#define mod 1000000007
#define N 100010
using namespace std;
inline ll read() {
	ll x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') f=(c=='-')?-1:1,c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
int n,a[N];
int main() {
	n=read();
	for (int i=1; i<=n; i++) a[i]=read();
	int ans=0;
	for (int i=1; i<=n; i++) {
		if (a[i]==i) {
			ans++;
			if (a[i+1]==i+1) i++;
		}
	}
	cout << ans << endl;
}