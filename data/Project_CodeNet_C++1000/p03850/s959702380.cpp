#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
int A[100011];
char op[11];
LL sums[100011], asums[100011];

void MAIN() {
    scanf("%d", &N);
    scanf("%d", A);
    for (int i=1; i<N; i++) {
	scanf("%s%d", op, A+i);
	if (*op == '-') A[i] = -A[i];
    }

    REP (i, N) {
	sums[i+1] = sums[i] + A[i];
	asums[i+1] = asums[i] + abs(A[i]);
    }
    LL ans = sums[N];
    REP (i, N) if (A[i] < 0) {
	int r = i+1;
	while (r < N && A[r] >= 0) r++;
	if (r < N) {
	    LL tmp = sums[i+1] - (sums[r] - sums[i+1]) + (asums[N] - asums[r]);
	    amax(ans, tmp);
	}
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

