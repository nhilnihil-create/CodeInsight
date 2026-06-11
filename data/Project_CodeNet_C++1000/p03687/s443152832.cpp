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

int n, ans = kInf; char str[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		scanf("%s", str + 1); n = strlen(str + 1);
		for(char t = 'a'; t <= 'z'; ++t) {
			int nxt = n + 1, cur_ans = 0;
			for(int i = n; i; --i) {
				if(str[i] == t) nxt = i;
				cur_ans = std::max(cur_ans, nxt - i);
			}
			ans = std::min(ans, cur_ans);
			//printf("%c %d\n", t, cur_ans);
		}
		printf("%d\n", ans);
	} return 0;
}