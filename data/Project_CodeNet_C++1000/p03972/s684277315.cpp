#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;

int p[2100000];
int tx[2100000];
int w, h;
long long ans;
int toth, totw;

bool cmp(int x, int y) {
	return p[x] < p[y];
}

int main() {
	scanf("%d%d", &w, &h);
	for (int i = 0; i < w + h; i++)
		scanf("%d", &p[i]);
	for (int i = 0; i < w + h; i++)
		tx[i] = i;
	sort(tx, tx + w + h, cmp);
	totw = 0;
	toth = 0;
	for (int i = 0; i < w + h; i++)
		if (tx[i] < w) {
			ans += 1LL * p[tx[i]] * (h + 1 - toth);
			totw += 1;
		}else {
			ans += 1LL * p[tx[i]] * (w + 1 - totw);
			toth += 1;
		}
	cout << ans << endl;
}
