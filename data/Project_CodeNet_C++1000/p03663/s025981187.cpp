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

#ifdef LOCAL
const int N = 9;
const string Ns = to_string(N);
char query(const string &s) {
    printf("? %s\n", s.c_str());

    LL n = 0;
    REP (i, s.size()) n = n * 10 + s[i] - '0';
    char ret;
    if (n <= N && s < Ns) ret = 'Y';
    else if (n > N && s > Ns) ret = 'Y';
    else ret = 'N';
    printf("ret %c\n", ret);

    return ret;
}
void answer(const string &s) {
    printf("! %s\n", s.c_str());
    printf("j %s\n", Ns.c_str());
    exit(0);
}
#else
char buf[11];
char query(const string &s) {
    printf("? %s\n", s.c_str());
    fflush(stdout);
    scanf("%s", buf);
    return *buf;
}
void answer(const string &s) {
    printf("! %s\n", s.c_str());
    exit(0);
}
#endif

void MAIN() {
    if (query("10000000000") == 'Y') {
	string S = "2";
	REP (i, 10) {
	    if (query(S) == 'Y') {
		S[0] = '1';
		answer(S);
	    }
	    S.push_back('0');
	}
    } else {
	string S = "1";
	for (int i=1; i<=9; i++) {
	    S.push_back('0');
	    if (query(S) == 'N') {
		S.pop_back();
		break;
	    }
	}

	// query(S) == 'Y';
	// query(S + '0') == 'N';
	REP (i, S.size()) S[i] = '9';
	for (int i=0; i<(int)S.size(); i++) {
	    int lo = -1, hi = 9;
	    if (i == 0) lo = 0;

	    while (hi - lo > 1) {
		int mid = (hi + lo) / 2;
		S[i] = mid + '0';
		if (query(S + "9") == 'N') {
		    lo = mid;
		} else {
		    hi = mid;
		}
	    }
	    S[i] = hi + '0';
	}

	answer(S);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}

