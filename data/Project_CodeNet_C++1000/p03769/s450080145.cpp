#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <deque>
#define rep(i, a, b) for (int i = (a), _ = (b); i <= _; ++ i)
#define per(i, a, b) for (int i = (a), _ = (b); i >= _; -- i)
#define For(i, a, b) for (int i = (a), _ = (b); i < _; ++ i)
#define ri rd<int>
#define rl rd<LL>
typedef long long LL;
using namespace std;
const int maxN = 207;
const int V = 200;

template<class T> inline T rd() {
	bool f = 1; char c = getchar(); for (; !isdigit(c); c = getchar()) if (c == '-') f = 0;
	T x = 0; for (; isdigit(c); c = getchar()) x = x * 10 + c - 48; return f ? x : -x;
}

LL n;
deque<int> ans;
int opr[maxN], kd[maxN], tt;

int main() {

	n = rl();
	int cur = 100;

	while (n) {
		++ tt;
		if (n % 2 == 0) {
			n--;
			opr[tt] = cur --;
			kd[tt] = 1;
		}
		else {
			n >>= 1;
			opr[tt] = cur --;
			kd[tt] = 2;
		}
	}
	per (i, tt, 1) kd[i] == 1 ? ans.push_front(opr[i]) : ans.push_back(opr[i]);
	per (i, tt, 1) ans.push_back(opr[i]);

	printf("%d\n", tt << 1);
	rep (i, 1, tt << 1) printf("%d%c", ans.front(), " \n"[i == tt << 1]), ans.pop_front();

	return 0;
}