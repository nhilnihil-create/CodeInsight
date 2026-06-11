#include<tuple>
#include<deque>
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

LL N;
deque<int> ans;

LL nCk(int n, int k) {
    LL ret = 1;
    REP (i, k) {
	ret *= n-i;
	ret /= i+1;
    }
    return ret;
}
LL F(LL a, LL b, LL c, LL d) {
    LL x = 0;
    for (int i=1; i<=min(a, c); i++) {
	x += nCk(a, i) * nCk(c, i);
    }
    LL y = 0;
    for (int i=1; i<=min(b, d); i++) {
	y += nCk(b, i) * nCk(d, i);
    }
    LL ret = x * y;
    ret += 1LL<<(a+c-1);
    ret += 1LL<<(b+d-1);
    ret -= 2;
    return ret;
}

void MAIN() {
    using Tuple = tuple<LL, int, int, int, int>;
    vector<Tuple> X;
    for (int a=0; a<=12; a++)
	for (int b=a; b<=12; b++)
	    for (int c=a; c<=12; c++)
		for (int d=b; d<=12; d++) 
		    X.emplace_back(F(a, b, c, d), a, b, c, d);
    sort(X.begin(), X.end());

    scanf("%lld", &N);
    int cur = 1;
    while (N >= 3) {
	Tuple key(N+1, -1, -1, -1, -1);
	int k = lower_bound(X.begin(), X.end(), key) - X.begin();
	k--;
	LL g;
	int a, b, c, d;
	tie(g, a, b, c, d) = X[k];
	N -= g;
	REP (i, a) ans.push_back(cur);
	REP (i, b) ans.push_back(cur+1);
	REP (i, c) ans.push_back(cur);
	REP (i, d) ans.push_back(cur+1);
	cur += 2;
    }

    while (N) {
	REP (t, 2) ans.push_back(cur);
	N--;
	cur++;
    }

    printf("%d\n", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

