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
LL L, T;
LL X[100011];
char W[100011];
LL B[100011];
LL ans[100011];

LL f(LL x, LL y) {
    return x / L + (x % L > y? 1: 0);
}

void MAIN() {
    scanf("%d%lld%lld", &N, &L, &T);
    REP (i, N) {
	scanf("%lld%s", X+i, W+i);
    }

    bool flip = (W[0] == '2');
    if (flip) {
	REP (i, N) {
	    W[i] = (W[i] == '1'? '2': '1');
	    X[i] = L-1-X[i];
	}
	reverse(W+1, W+N);
	reverse(X+1, X+N);
    }

    LL cross = 0;
    REP (i, N) if (W[i] == '2') {
	LL x = X[0], y = X[i];
	cross += f(x+2*T, y) - f(x, y);
    }

    REP (i, N) {
	if (W[i] == '1') {
	    B[i] = (X[i] + T) %L;
	} else {
	    B[i] = (X[i] - T) %L;
	    if (B[i] < 0) B[i] += L;
	}
    }
    sort(B, B+N);
    REP (i, N) if (B[i] == (X[0]+T)%L) {
	REP (j, N) {
	    ans[(cross+j)%N] = B[(i+j)%N];
	}
	break;
    }

    if (flip) {
	REP (i, N) {
	    ans[i] = L-1-ans[i];
	}
	reverse(ans+1, ans+N);
    }
    REP (i, N) printf("%lld\n", ans[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

