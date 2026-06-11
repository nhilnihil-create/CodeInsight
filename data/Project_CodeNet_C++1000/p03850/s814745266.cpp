#include <cstdio>
#include <iostream>
#define debug(...) fprintf(stderr, __VA_ARGS__)
using namespace std;
inline char nc() {
	return getchar();
	static char buf[100000], *l = buf, *r = buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
template<class T> void read(T &x) {
	x = 0; int f = 1, ch = nc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
	x *= f;
}
typedef long long ll;
const int maxn = 1e5 + 5;
int n;
int a[maxn];
ll sum[maxn];
ll solve() {
	ll an = sum[n];
	ll x = 0, y = 0;
	for(int i = n; i >= 1; --i) {
		if(a[i] < 0) {
			an = max(an, sum[i - 1] + a[i] - x + y);
			y += x - a[i];
			x = 0;
		}
		else {
			x += a[i];
		}
	}
	return an;
}
int main() {
	read(n);
	for(int i = 1; i <= n; ++i) {
		read(a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	printf("%lld\n", solve());
	return 0;
} 