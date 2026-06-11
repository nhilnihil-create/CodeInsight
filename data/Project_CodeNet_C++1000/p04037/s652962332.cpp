#include<bits/stdc++.h>
using namespace std;
#define il inline
#define re register
#define debug printf("Now is Line : %d\n",__LINE__)
#define file(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
//#define int long long
#define D double
#define inf 123456789
#define mod 1000000007
il int read() {
    re int x = 0, f = 1; re char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
    return x * f;
}
#define rep(i, s, t) for(re int i = s; i <= t; ++ i)
#define drep(i, s, t) for(re int i = t; i >= s; -- i)
#define Next(i, u) for(re int i = head[u]; i; i = e[i].next)
#define mem(k, p) memset(k, p, sizeof(k))
#define lb(x) (x)&(-(x))
#define ls k * 2
#define rs k * 2 + 1
#define maxn 100005
int n, m, a[maxn];
il bool cmp(int a, int b) {
	return a > b;
}
il int doit(int x, int y) {
	int ans = 0;
	while(a[x + 1] == y) ans ^= 1, ++ x;
	return ans;
}
int main() {
	//file(a);
	n = read();
	rep(i, 1, n) a[i] = read();
	sort(a + 1, a + n + 1, cmp);
	int nx = 0;
	while(1) {
		++ nx;
		if(a[nx] < nx) break;
	}
	-- nx;
	if(((a[nx] - nx) & 1) || doit(nx, nx)) printf("First");
	else printf("Second");
	return 0;
}