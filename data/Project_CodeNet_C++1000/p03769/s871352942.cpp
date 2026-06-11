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

typedef long long ll;
typedef double ff;
typedef std::pair<int, int> pii;

std::deque <int> s;

int main() {
	ll n; rd(n); ++n;
	int ptr = 0, ans = 1;
	for(int i = 50; ~i; --i) {
		if((n >> i) && !(n >> (i + 1))) {
			//s.push_back(++ptr); ans = 2;
		} else if(n >> i) {
			//s.push_back(++ptr);//printf("??? %d %lld\n", i, n >> i);
			s.push_back(++ptr); ans *= 2;
			if((n >> i) & 1) {
				//printf("???3\n");
				s.push_front(++ptr);
				ans += 1;
			}
			//if(i) s.push_back(++ptr), ans *= 2;
		}
		//printf("Ans = %d\n", ans);
	}
	printf("%d\n", s.size() + ptr);
	for(auto x : s) printf("%d ", x);
	for(int i = 1; i <= ptr; ++i) printf("%d ", i);
	return 0;
}