/*
	设 f[i] 为点 i 可以往上传的值
	设一个方程发现在某个点配对的个数和上传的个数是固定的
*/
#include <iostream>
#include <cstdio>
#include <vector>
#define N 100005

using namespace std;

int n;
int a[N], f[N];

vector<int> g[N];

inline void read(int &x) {
	x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
}
void dfs(int u, int fa) {
	int S = g[u].size();
	if(S == 1) { return f[u] = a[u], void(); }
	int Max = 0, sum = 0;
	for(int i = 0; i < S; ++i) {
		int v = g[u][i];
		if(v == fa) continue;
		dfs(v, u);
		sum += f[v];
		Max = max(Max, f[v]);
	}
	/*
		A : 配对的个数, B : 上传的个数
	    { A + B = a[u];
	    { 2 * A + B = sum;
	*/
	int A = sum - a[u], B = a[u] - A;
	if(A < 0 || B < 0 || A > min(sum - Max, sum / 2)) {
		puts("NO");
		exit(0);
	}
	f[u] = B;
	return;
}

int main() {
	read(n);
	for(int i = 1; i <= n; ++i) read(a[i]);
	for(int i = 1, u, v; i < n; ++i) {
		read(u), read(v);
		g[u].push_back(v), g[v].push_back(u);
	}
	if(n == 2) {
		puts(a[1] == a[2] ? "YES" : "NO");
		return 0;
	}
	for(int i = 1; i <= n; ++i) 
		if(g[i].size() != 1) {
			dfs(i, 0);
			puts(f[i] ? "NO" : "YES");
			break;
		}
	return 0;
}