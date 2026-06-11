/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int h, w, d;
	scanf("%d%d%d", &h, &w, &d);
	int res[h][w];
	forn(i, h) {
		forn(j, w) {
			res[i][j] = ((i + j) / d % 2) * 2 + ((i - j + w) / d % 2);
			putchar("RYGB"[res[i][j]]);
		}
		puts("");
	}
	// forn(i, h) 
	// 	forn(j, w) 
	// 		forn(i1, h) 
	// 			forn(j1, w) 
	// 				if (abs(i - i1) + abs(j - j1) == d)
	// 					assert(res[i][j] != res[i1][j1]);
}
