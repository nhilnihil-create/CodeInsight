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

const int kN = 1e6 + 5;

int c[kN], n; bool bg[kN];

int main() {
	rd(n);
	for(int i = 1; i <= n; ++i) {
		int x; rd(x);
		c[x] = i; bg[x] = true;
	}
	for(int i = 1, ptr = 1; i <= n * n; ++i) {
		if(c[i] && bg[i]) {
			int j;
			for(j = 1; ptr < i && j < c[i]; ++j, ++ptr) {
				while(c[ptr]) ++ptr;
				c[ptr] = c[i];
			}
			if(j < c[i]) {
				printf("No\n");
				return 0;
			}
		}
	}
	for(int i = n * n, ptr = n * n; i; --i) {
		if(c[i] && bg[i]) {
			int j;
			for(j = 1; ptr > i && j <= n - c[i]; ++j, --ptr) {
				while(c[ptr]) --ptr;
				c[ptr] = c[i];
			}
			if(j <= n - c[i]) {
				printf("No\n");
				return 0;
			}
		}
		//for(int i = 1; i <= n * n; ++i) printf("%d ", c[i]);
		//	printf("\n");
	}
	printf("Yes\n");
	for(int i = 1; i <= n * n; ++i) printf("%d ", c[i]);
	printf("\n");
	return 0;
}