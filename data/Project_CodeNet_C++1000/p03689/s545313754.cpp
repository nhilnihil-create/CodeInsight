#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int H, W, h, w;
int A[1011][1011];

void MAIN() {
    scanf("%d%d%d%d", &H, &W, &h, &w);
    bool yes = true;
    if (1 < w && W % w) {
	REP (i, H) {
	    int z = W/w;
	    for (int j=0; j<W; j+=w) {
		A[i][j] = z+1;
		A[i][j+w-1] = -z-2;
	    }
	}
    } else if (1 < h && H % h) {
	REP (j, W) {
	    int z = H/h;
	    for (int i=0; i<H; i+=h) {
		A[i][j] = z+1;
		A[i+h-1][j] = -z-2;
	    }
	}
    } else {
	yes = false;
    }

    if (yes) {
	puts("Yes");
	REP (i, H) rprintf("%d", A[i], A[i]+W);
    } else {
	puts("No");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

