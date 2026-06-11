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

int N;
int A[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, 2*N-1) scanf("%d", A+i);
    int center = N-1;
    int lo = 1, hi = 2*N-1;
    while (hi - lo > 1) {
	int mid = (hi + lo) / 2;

	bool res = (mid <= A[center]);
	if (N % 2 == 0) res = !res;
	REP (k, N-1) {
	    bool b0 = mid <= A[center-k-1];
	    bool b1 = mid <= A[center-k];
	    bool c0 = mid <= A[center+k];
	    bool c1 = mid <= A[center+k+1];
	    if (b0 == b1) {
		res = b0;
		break;
	    } else if (c0 == c1) {
		res = c0;
		break;
	    }
	}

	(res? lo: hi) = mid;
    }

    printf("%d\n", lo);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

