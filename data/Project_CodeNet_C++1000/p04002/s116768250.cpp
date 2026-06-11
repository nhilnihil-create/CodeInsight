//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100000

int n, m;

set<pair<int,int>> s;
long cnt[10];

int input() {
	int k;
	if (scanf("%d %d %d", &n, &m, &k) < 0) return 0;
	for (int i=0; i<k; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		s.insert({x, y});
	}
	return 1;
}

void init() {
	memset(cnt, 0, sizeof(cnt));
}

int solve() {
	cnt[0] = long(n-2) * (m-2);
	for (auto p: s) {
		int pi = p.first, pj = p.second;
		for (int i=pi-2; i<=pi; i++) {
			if (i<1 || i+2>n) continue;
			for (int j=pj-2; j<=pj; j++) {
				if (j<1 || j+2>m) continue;
				int k = 0;
				int ok = 1;
				for (int di=0; di<3; di++) {
					for (int dj=0; dj<3; dj++) {
						int ni = i+di, nj = j+dj;
						if (s.count({ni, nj})) {
							if (ni < pi || (ni==pi && nj < pj)) {
								ok = 0;
								break;
							}
							k++;
						}
					}
				}
				cnt[k] += ok;
			}
		}
	}
	for (int i=1; i<10; i++)
		cnt[0] -= cnt[i];
	return 1;
}

void output(int ans) {
	for (int i=0; i<10; i++)
		printf("%ld\n", cnt[i]);
}

void cleanup() {
	s.clear();
}

int main() {
	//int ca; scanf("%d", &ca);
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}



