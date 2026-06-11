//Created Time:2019年12月18日 星期三 10时13分52秒
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define N 200005

using namespace std;

int n, m, cnt;
int a[N], b[N], c[N], d[N];
bool vis[N];
long long k;

vector < int > g[N];

int read();

int main(){
	n = read();
	for(int i = 1; i <= n; ++i) a[i] = read(), c[i] = i;
	for(int i = n; i; --i) a[i] -= a[i - 1];
	m = read(); cin >> k;
	for(int i = 1; i <= m; ++i)
		b[i] = read(), swap(c[b[i]], c[b[i] + 1]);
	for(int i = 1; i <= n; ++i){
		if(vis[i]) continue;
		int now = i; ++cnt;
		while(!vis[now]) 
			g[cnt].push_back(now), vis[now] = true, now = c[now];
	}
	for(int i = 1; i <= cnt; ++i){
		int sz = g[i].size(), tmp = k % sz;
		for(int j = 0; j < sz; ++j)
			d[g[i][(j - tmp + sz) % sz]] = g[i][j];
	}
	long long ans = 0;
	for(int i = 1; i <= n; ++i)
		ans += a[d[i]], printf("%.1lf\n",(double)ans);
	return 0;
}

int read(){
	int x = 0, f = 0; char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for(; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? -x : x;
}
