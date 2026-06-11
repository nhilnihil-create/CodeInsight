#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define str string
#define fi first
#define se second
#define pb push_back
#define SET(a, b) memset(a, b, sizeof(a))
#define eps 1e-6
#define pi atan(1) * 4
#define mod 1000000007
#define inf 1000000000
using namespace std;
bool pbt[505][505][4];
int cnt[505][505];
set<pii> st[5];
int color[505][505];
char ch[4] = {'R', 'Y', 'G', 'B'};
int main () {
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q;
	scanf("%d %d %d", &a, &b, &c);
	for (i = 1; i <= a; i++) {
		for (j = 1; j <= b; j++) {
			st[4].insert({i, j});
		}
	}
	SET(pbt, 0); SET(color, -1); SET(cnt, 0);
	int tx, ty, lft = a * b;
	pii v;
	while (lft > 0) {
			for (k = 2; k <= 4; k++) {
				if (st[k].empty()) continue;
				v = *st[k].begin(); st[k].erase(v);
				break;
			}
			p = v.fi; q = v.se;
			queue<pii> bfs;
			for (k = 0; k <= 3; k++) {
				if (!pbt[p][q][k]) {
					color[p][q] = k;
					break;
				}
			}
			bfs.push({p, q}); lft--;
			while (!bfs.empty()) {
				auto u = bfs.front(); bfs.pop();
				for (i = -c; i <= c; i++) {
					j = c - abs(i);
					tx = u.fi + i; ty = u.se + j;
					if (tx >= 1 && tx <= a && ty >= 1 && ty <= b && color[tx][ty] == -1) {
						if (!pbt[tx][ty][color[u.fi][u.se]]) {
							pbt[tx][ty][color[u.fi][u.se]] = true;
							st[4 - cnt[tx][ty]].erase({tx, ty});
							if (++cnt[tx][ty] == 3) {
								for (k = 0; k <= 3; k++) {
									if (!pbt[tx][ty][k]) {
										color[tx][ty] = k;
										break;
									}
								}
								lft--;
								bfs.push({tx, ty});
							}
							st[4 - cnt[tx][ty]].insert({tx, ty});
						}
					}
					j = -(c - abs(i));
					tx = u.fi + i; ty = u.se + j;
					if (tx >= 1 && tx <= a && ty >= 1 && ty <= b && color[tx][ty] == -1) {
						if (!pbt[tx][ty][color[u.fi][u.se]]) {
							pbt[tx][ty][color[u.fi][u.se]] = true;
							st[4 - cnt[tx][ty]].erase({tx, ty});
							if (++cnt[tx][ty] == 3) {
								for (k = 0; k <= 3; k++) {
									if (!pbt[tx][ty][k]) {
										color[tx][ty] = k;
										break;
									}
								}
								lft--;
								bfs.push({tx, ty});
							}
							st[4 - cnt[tx][ty]].insert({tx, ty});
						}
					}
				}
			}
	}
	for (i = 1; i <= a; i++) {
		for (j = 1; j <= b; j++) {
			printf("%c", ch[color[i][j]]);
		}
		printf("\n");
	}
	return 0;
}