/********************************************************************************
	
	Code by a weak man named CYJian, and he hopes the code can get more points.

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
#define FILE(s) freopen(s"in", "r", stdin), freopen(s"out", "w", stdout)

template<typename T>
inline void read(T &x) {
	char ch, t = 0; x = 0;
	while(!isdigit(ch = ge)) t |= ch == '-';
	while(isdigit(ch)) x = x * 10 + (ch ^ 48), ch = ge;
	x = t ? -x : x;
}
inline int read_int() { int x; return read(x), x; }
inline ll read_ll() { ll x; return read(x), x; }

template<typename T> inline void chkmin(T&a, T b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T&a, T b) { a = a > b ? a : b; }
//}}}

const int MAXN = 100010;

int a[MAXN];
int op[MAXN];
ll suf[MAXN];
ll pre[MAXN];

int main() {
#ifdef LOCAL
	FILE("");
#endif

	int n = ri - 1;
	pre[0] = a[0] = ri;
	for(int i = 1; i <= n; i++) {
		char opt = ge;
		while(opt != '-' && opt != '+') opt = ge;
		op[i] = opt == '-' ? -1 : 1;
		a[i] = ri, pre[i] = pre[i - 1] + (opt == '-' ? -a[i] : a[i]);
	}

	for(int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];

	ll res = pre[n];
	int las = n + 1;
	for(int i = n; i >= 1; i--)
		if(op[i] == -1) {
			chkmax(res, pre[i - 1] + suf[las] * 2 - suf[i]);
			las = i;
		}
	cout << res << endl;
	return 0;
}