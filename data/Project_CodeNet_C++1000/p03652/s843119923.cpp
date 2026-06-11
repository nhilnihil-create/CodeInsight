/********************************************************************************
	
	Code by a weak man who named CYJian, and he hopes the code can get more points.

	Algorithm: 

 ********************************************************************************/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//{{{ FAST IO AND SOME FUNCTIONS
const int __SIZE = 1 << 18;
char ibuf[__SIZE], *iS, *iT;

#define ge (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
#define ri read_int()
#define rl read_ll()
#define ra read_alpha()
#define FILE(s) freopen(s"in", "r", stdin), freopen(s"out", "w", stdout)

template<typename T>
inline void read(T &x) {
	char ch, t = 0; x = 0;
	while(!isdigit(ch = ge)) t |= ch == '-';
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = ge;
	x = t ? -x : x;
}
inline char read_alpha() { char c = ge; while(!isalpha(c) && c != EOF) c = ge; return c; }
inline int read_int() { int x; return read(x), x; }
inline ll read_ll() { ll x; return read(x), x; }

template<typename T> inline void chkmin(T&a, T b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T&a, T b) { a = a > b ? a : b; }
//}}}

vector<int>b[310];
int a[310][310];
int ban[310];
int sz[310];
int p[310];

int main() {
#ifdef LOCAL
	FILE("");
#endif

	int n = ri, m = ri;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++)
			a[i][j] = ri;
		b[a[i][1]].push_back(i);
		sz[a[i][1]]++;
		p[i] = 1;
	}
	int mi = n;
	for(int i = 1; i < m; i++) {
		int t = 0;
		for(int j = 1; j <= m; j++)
			if(!ban[j] && sz[j] > sz[t])
				t = j;
		chkmin(mi, sz[t]), ban[t] = 1;
		for(auto u : b[t]) {
			for(int&j = p[u]; j <= m; j++) {
				if(!ban[a[u][j]]) {
					sz[a[u][j]]++;
					b[a[u][j]].push_back(u);
					break;
				}
			}
		}
	} cout << mi << endl;
	return 0;
}