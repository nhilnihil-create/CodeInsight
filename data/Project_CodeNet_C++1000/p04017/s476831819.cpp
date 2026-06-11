#include<bits/stdc++.h>

#define ll long long
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)

using namespace std;

typedef pair<int, int> pii;
typedef double db;
const int N = 1e5 + 50;
int n, a[N], f[N][36], L, Q; 
inline int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar();}
	while(ch >='0' && ch <='9') { x = (x<<3)+(x<<1)+(ch^48); ch = getchar();}
	return x*f;
}
void init(){
	n = read();
	rep(i, 1, n) a[i] = read();
	L = read(); Q = read();
	rep(i, 1, n) f[i][0] = (int) (upper_bound(a+1, a+n+1, a[i] + L) - a - 1);
	rep(j, 1, 30) rep(i, 1, n) f[i][j] = f[f[i][j-1]][j-1];
	while(Q --> 0) {
		int ans = 0, l = read(), r = read();
		if(l > r) swap(l, r);
		int now = l;
		per(i, 30, 0) if(f[now][i] < r) ans += (1<<i), now = f[now][i];
		printf("%d\n", ans+1); 
	}
}
int main(){
//	freopen("input.in","r",stdin);
//	freopen("output.out","w",stdout);
	init();
	return 0;
}
