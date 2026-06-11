#include <stdio.h>
#pragma warning(disable:4996)
//FILE *in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");
FILE *in = stdin, *out = stdout;
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 0x7fffffff
#define NM 100005
#define MOD 1000000007
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
#define si(n) fscanf(in,"%d",&n)
#define sd(n) fscanf(in,"%lf",&n)
typedef long long int ll;

int ans=123;
char test(ll X) {
	//*
	fprintf(out, "? %lld\n", X);
	fflush(stdout);
	char ch[5]; fscanf(in, "%s", ch);
	//*/
	return ch[0];
}
void Find(int X) {
	fprintf(out, "! %d\n", X);
}

int getLen() {
	int L = 0, R = 8, len = 9;
	while (L <= R) {
		int m = (L + R) >> 1;
		int X = 1;
		FOR(i, 1, m) X *= 10;
		if (test(X) == 'N') {
			len = min(len, m);
			R = m - 1;
		}
		else {
			L = m + 1;
		}
	}
	/*for (ll X = 1; len < 9; len++, X *= 10) {
		if (test(X) == 'N') {
			return len;
		}
	}*/
	return len;
}
int main() {
	int len = getLen();
	if (len == 9 && test(1000000000) == 'Y') { // 10^k 꼴 or 9자리
		len = 0;
		for (ll X = 2; len <= 9; len++, X *= 10) {
			char ch = test(X);
			if (ch == 'Y') {
				Find(X / 2);
				return 0;
			}
		}
	}
	int ans = 0;
	FOR(k, 1, len - 1) {
		int L = 0, R = 9, v = 9;
		if (k == 1) L = 1;
		while(L<=R){
			int m = (L + R) >> 1;
			int X = ans * 10 + m;
			if (test(X) == 'N') {
				v = min(v, m - 1);
				R = m - 1;
			}
			else {
				L = m + 1;
			}
		}
		ans = ans * 10 + v;
	}
	{ // last digit
		int L = 0, R = 9, v = -1;
		if (len == 1) L = 1;
		FOR(i, L, R) {
			ll X = ((ll)ans * 10 + i) * 10;
			if (test(X) == 'Y') {
				Find(ans * 10 + i);
				return 0;
			}
		}
	}
	return 0;
}