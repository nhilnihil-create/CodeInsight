/*
	每次把最多的那个鸽了
	统计一遍答案
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#define N 305

using namespace std;

int n, m;
int a[N][N];
int cnt[N], isAbo[N];

inline void read(int &x) {
	x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
}

int main() {
	read(n), read(m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			read(a[i][j]);
	int ans = n, res, p;
	for(int o = 1; o < m; ++o) {
		memset(cnt, 0, sizeof cnt);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				if(!isAbo[a[i][j]]) {
					++cnt[a[i][j]];
					break;
				}
			}
		}
		res = p = 0;
		for(int i = 1; i <= m; ++i)
			if(cnt[i] > res) {
				res = cnt[i], p = i;
			}
		if(res < ans) ans = res;
		isAbo[p] = true;
	}
	printf("%d\n", ans);
	return 0;
}