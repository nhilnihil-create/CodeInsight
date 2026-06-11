#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#define rep(i, a, b) for (int i = (a), _ = (b); i <= _; ++ i)
#define per(i, a, b) for (int i = (a), _ = (b); i >= _; -- i)
#define For(i, a, b) for (int i = (a), _ = (b); i < _; ++ i)
#define ri rd<int>
using namespace std;
typedef long long LL;

template<class T> inline T rd() {
	bool f = 1; char c = getchar(); for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	T x = 0; for (; isdigit(c); c = getchar()) x = x * 10 + c - 48; return f ? x : -x;
}

inline int ask(LL x) {
	static char s[7];
	printf("? %lld\n", x); fflush(stdout);
	scanf("%s", s);
	return s[0] == 'Y';
}

inline void wow(LL x) {
	printf("! %lld\n", x); fflush(stdout);
	exit(0);
}

void solve1(LL r) {
	LL l = r / 10; --r;
	while (l < r) {
		LL mid = (l + r) >> 1;
		if (ask(mid * 10)) r = mid;
		else l = mid + 1;
	}
	wow(r);
}

void solve2() {
	for (LL t = 1, i = 0; i <= 10; ++ i, t *= 10LL)
		if (ask(t+1)) wow(t);
}

int main() {

	for (LL t = 1, i = 0; i <= 10; ++ i, t *= 10LL)
		if (!ask(t)) solve1(t);

	solve2();

	return 0;
}