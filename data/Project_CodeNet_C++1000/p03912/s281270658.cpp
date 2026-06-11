#include <bits/stdc++.h>
#define rep(i, n) for (rint i = 1; i <= (n); i ++)
#define re0(i, n) for (rint i = 0; i < (int) n; i ++)
#define travel(i, u) for (rint i = head[u]; i; i = e[i].nxt)
#define rint register int
using namespace std;

typedef long long lo;

template<typename tp> inline void read(tp &x) {
    x = 0; char c = getchar(); int f = 0;
    for (; c < '0' || c > '9'; f |= c == '-', c = getchar());
    for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
    if (f) x = -x;
}
const int N = 3e5 + 233;
int n, m, one[N], zero[N], ans;
map <int, int> mp;

int main(void) {
    read(n); read(m);
    rep (i, n) {
	int x; read(x); mp[x]++;
    }
    for (auto i : mp) {
	int res = i.first % m;
	one[res] += i.second & 1;
	zero[res] += i.second - (i.second & 1);
    }
    ans += one[0] / 2 + zero[0] / 2;
    for (int i = 1; i < m - i; i++) {
	int one1 = one[i];
	int zero1 = zero[i];
	int one2 = one[m - i];
	int zero2 = zero[m - i];
	if (one1 < one2) swap(one1, one2), swap(zero1, zero2);
	ans += one2; one1 -= one2; one2 = 0;
	if (zero2 < one1) {
	    ans += zero2;
	} else {
	    ans += one1 + (zero2 - one1) / 2;
	}
	ans += zero1 / 2;	
    }
    if (m % 2 == 0) {
	ans += one[m / 2] / 2 + zero[m / 2] / 2;
    }
    cout << ans << "\n";
}
