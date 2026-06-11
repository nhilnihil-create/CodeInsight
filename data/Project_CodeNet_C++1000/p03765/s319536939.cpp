//#include "debug.h"
#include <string.h>
#include <limits.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 100002

int n;
char s[MAXN], t[MAXN];
int sa[MAXN], sb[MAXN], ta[MAXN], tb[MAXN];

int input() {
	if (scanf("%s %s", s, t) < 0) return 0;
	return 1;
}

void init() {
}

void calc(char *s, int *sa, int *sb) {
	sa[0] = sb[0] = 0;
	for (int i=0; s[i]; i++) {
		sa[i+1] = sa[i] + (s[i]=='A');
		sb[i+1] = sb[i] + (s[i]=='B');
	}
}

int result(int *sa, int *sb, int i, int j) {
	int ka = sa[j]-sa[i-1];
	int kb = sb[j]-sb[i-1];
	int k = abs(ka-kb) % 3;
	//printf("%d %d %d==\n", ka, kb, k);
	if (k && ka<kb) k = 3-k;
	return k;
}

void prints(char *s, int a, int b) {
	for (int i=a-1; i<b; i++) printf("%c", s[i]);
	printf("\n");
}

long solve() {
	calc(s, sa, sb);
	calc(t, ta, tb);

	int q;
	scanf("%d", &q);
	for (int i=0; i<q; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		//prints(s, a, b); prints(t, c, d);
		int fs = result(sa, sb, a, b);
		int ft = result(ta, tb, c, d);
		printf("%s\n", (fs==ft? "YES":"NO"));
	}
	return 1;
}

void output(long ans) {
}

void cleanup() {
}

int main() {
	while (input()) {
		init();
		output(solve());
		cleanup();
		//break;
	}
}



