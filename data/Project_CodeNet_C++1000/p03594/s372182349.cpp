#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>

#ifndef ONLINE_JUDGE
	#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#else
	#define DEBUG(x) do {} while(0);
#endif

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define FOR(i, A, N) for(int (i) = (A); (i) < (N); (i)++)
#define REP(i, N) for(int (i) = 0; (i) < (N); (i)++)

using namespace std;
typedef long long ll;
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

int n,m,d;
#define eps 0.0000000001l

int main() {
	scanf("%d%d%d", &n, &m, &d);
	REP(i, n) {
		REP(j, m) {
//		int nr = i+j, nc = j-i;
			int nr = (i+j), nc = (j-i);
			int remr = nr%(2*d), remc = (nc+2*d*500)%(2*d);
			int col = 0;
			if(remr < d && remc >= d)
				col = 1;
			else if(remr < d && remc < d) {
				col = 2;
			} else if(remr >= d && remc >= d) {
				col = 3;
			}
			printf("%c", "RGBY"[col]);
		}
		printf("\n");
	}
	return 0;
}
