#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

namespace io {
#define gc() (iS == iT ? (iT = (iS = ibuff) + fread(ibuff, 1, SIZ, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
	const int SIZ = 1 << 21 | 1;
	char *iS, *iT, ibuff[SIZ], obuff[SIZ], *oS = obuff, *oT = oS + SIZ - 1, fu[110], c;
	int fr;
	inline void out() {
		fwrite(obuff, 1, oS - obuff, stdout);
		oS = obuff;
	}
	template<class Type>
	inline void read(Type &x) {
		x = 0;
		Type y = 1;
		for (c = gc(); (c > '9' || c < '0') && c != '-'; c = gc());
		c == '-' ? y = -1 : x = (c & 15);
		for (c = gc(); c >= '0' && c <= '9'; c = gc())
			x = x * 10 + (c & 15);
		x *= y;
	}
	template<class Type>
	inline void print(Type x, char text = '\n') {
		if (x < 0)
			*oS++ = '-', x *= -1;
		if (x == 0)
			*oS++ = '0';
		while (x)
			fu[++fr] = x % 10 + '0', x /= 10;
		while (fr)
			*oS++ = fu[fr--];
		*oS++ = text;
		out();
	}
}
using namespace io;
#define ll long long
using namespace std;
const int maxn = 1e5 + 5;

vector<int> g[maxn];
int mx[maxn], n, col[maxn], q, d[maxn], ch[maxn], m, p[maxn];

void dfs(int x) {
	if (!col[x])
		col[x] = ch[q];
	for (int i : g[x])
		if (mx[x] - 1>mx[i])
			mx[i] = mx[x] - 1, dfs(i);
}

int main() {
	memset(mx, -1, sizeof(mx));
	read(n), read(m);
	for (int i = 1, uu, vv; i <= m; i++)
		read(uu), read(vv), g[uu].push_back(vv), g[vv].push_back(uu);
	read(q);
	for (int i = 1; i <= q; i++)
		read(p[i]), read(d[i]), read(ch[i]);
	for (; q; q--)
		if (d[q]>mx[p[q]]) mx[p[q]] = d[q], dfs(p[q]);
	for (int i = 1; i <= n; i++)
		print(col[i]);
	return 0;
}