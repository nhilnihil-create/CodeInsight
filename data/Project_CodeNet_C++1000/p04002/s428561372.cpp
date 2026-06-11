#include<cstdio>
#include<map>
using namespace std;
pair<int, int> p;
map<pair<int, int>, bool> grid;
int h, w, n;
long long cnt[10];
int main() {
	scanf("%d%d%d", &h, &w, &n);
	int i,j;
	for (i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		grid[make_pair(a, b)] = true;
	}
	for (auto iter = grid.begin(); iter != grid.end(); iter++) {
		if (!iter->second) continue;
		int x=iter->first.first,y=iter->first.second;
		for (int cx = 1; cx <= 3; cx++) {
			for (int cy = 1; cy <= 3; cy++) {
				bool inclusive = true;
				int count = 0;
				for (i = 1; i <= 3; i++) {
					for (j = 1; j <= 3; j++) {
						int nx = x + i-cx,ny=y+j-cy;
						if (nx<1 || nx>h || ny<1 || ny>w) inclusive = false;
						count += grid[make_pair(nx, ny)];
					}
				}
				if (inclusive) cnt[count]++;
			}
		}
	}
	cnt[0] = (long long)(h - 2)*(w - 2);
	for (i = 1; i <= 9; i++) {
		cnt[i] /= i;
		cnt[0] -= cnt[i];
	}
	for (i = 0; i <= 9; i++) printf("%lld\n", cnt[i]);
	return 0;
}