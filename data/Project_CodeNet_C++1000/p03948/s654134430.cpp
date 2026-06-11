//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100000

int n, t;
int a[MAXN];

int input() {
	if (scanf("%d %d", &n, &t) < 0) return 0;
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	return 1;
}

void init() {
}

int solve() {
	set<int> s;
	s.insert(a[0]);
	int p=INT_MIN, r=0;
	for (int i=1; i<n; i++) {
		int x = a[i] - *s.begin();
		if (x>p) {
			p = x;
			r = 1;
		}
		else if (x==p) {
			r++;
		}
		s.insert(a[i]);
	}
	return r;
}

void output(int ans) {
	printf("%d\n", ans);
}

void cleanup() {
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



