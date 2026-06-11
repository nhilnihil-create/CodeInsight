#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int kN = 4e5 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 998244353, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

ll A, B, C;
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		rd(A, B, C);
		for(int i = 1; i <= 40; ++i) {
			if(A % 2 || B % 2 || C % 2) {
				printf("%d\n", i - 1);
				return 0;
			}
			ll tA = A, tB = B, tC = C;
			A = (tB + tC) / 2;
			B = (tA + tC) / 2;
			C = (tB + tA) / 2;
			//printf("%lld %lld %lld\n", A, B, C);
		}
		printf("-1\n");
	} return 0;
}