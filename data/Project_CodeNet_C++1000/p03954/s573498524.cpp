#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
inline char nc() {
	static char buf[100000], *l = buf, *r = buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
template<class T> void read(T &x) {
	x = 0; int f = 1, ch = nc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
	x *= f;
}
const int inf = 1e9;
const int maxm = 200000 + 5;
int n, m, a[maxm], l, r; 
int mark[maxm];
int judge(int x) {
	for(int i = n, j = n; i > 1; --i, ++j) {
		if(a[i] >= x && a[i - 1] >= x) return 1;
		if(a[j] >= x && a[j + 1] >= x) return 1;
		if(a[i] <  x && a[i - 1] <  x) return 0;
		if(a[j] <  x && a[j + 1] <  x) return 0;
	}
	return a[1] >= x;
}
int sol() {
	int an = -1;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(judge(mid)) l = mid + 1, an = mid;
		else r = mid - 1;
	}
	return an;
} 
int main() {
//	freopen("testdata.in", "r", stdin);
	l = inf, r = -inf;
	read(n), m = (n << 1) - 1;
	for(int i = 1; i <= m; ++i) {
		read(a[i]);
		l = min(l, a[i]);
		r = max(r, a[i]);
	}
	printf("%d\n", sol());
	return 0;
}