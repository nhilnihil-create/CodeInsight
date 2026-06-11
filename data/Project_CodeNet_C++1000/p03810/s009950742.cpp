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
int A[100011];

bool wins() {
    int even = 0;
    REP (i, N) if (A[i] % 2 == 0) even++;
    if (even % 2) return true;
    if (even + 1 != N) return false;

    REP (i, N) {
	if (A[i] == 1) return false;
	if (A[i] % 2) A[i]--;
    }
    int g = 0;
    REP (i, N) g = __gcd(g, A[i]);
    REP (i, N) A[i] /= g;
    return !wins();
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    bool fst = wins();
    puts(fst? "First": "Second");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

