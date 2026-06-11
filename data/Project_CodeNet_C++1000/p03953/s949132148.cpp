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
int M;
LL K;
LL X[100011];
int A[100011];
int Z[60][100011];
int idx[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int x;
	scanf("%d", &x);
	X[i] = x;
    }

    scanf("%d%lld", &M, &K);
    REP (i, M) scanf("%d", A+i), A[i]--;

    REP (i, N-1) idx[i] = i;
    REP (i, M) {
	swap(idx[A[i]-1], idx[A[i]]);
    }
    REP (i, N-1) Z[0][idx[i]] = i;
    REP (t, 59) REP (i, N-1) Z[t+1][i] = Z[t][Z[t][i]];

    vector<LL> cur(N-1), nxt(N-1);
    REP (i, N-1) cur[i] = X[i+1] - X[i];
    REP (t, 60) if (K>>t&1) {
	REP (i, N-1) nxt[Z[t][i]] = cur[i];
	swap(cur, nxt);
    }

    LL x = X[0];
    printf("%lld\n", x);
    REP (i, N-1) {
	x += cur[i];
	printf("%lld\n", x);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

