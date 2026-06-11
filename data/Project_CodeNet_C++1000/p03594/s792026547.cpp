#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define maxn 1001
#define re register
#define FOR(i, l, r) for(re int i = l; i <= r; ++i)
#define DFR(i, l, r) for(re int i = l; i >= r; --i)
using namespace std;

int n, m, c, r, t, x, y, z;
char b[2][2];

int main() {
	b[0][0] = 'R';
	b[1][0] = 'Y';
	b[0][1] = 'G';
	b[1][1] = 'B';
	scanf("%d%d%d", &n, &m, &t);
	FOR(i, 1, n) {
		FOR(j, 1, m) {
	  	    x = i+j; y = i-j+m;
			putchar(b[x/t%2][y/t%2]);
	  	}
	  	putchar(10);
	}
}