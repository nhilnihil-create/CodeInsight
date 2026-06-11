/*
新图中(x, y)和(p, q)联通，当且仅当：存在一条长度为l的从x走到p的路径，和一条长度为l的从y走到q的路径
因为可以在一条边上来回走，所以只要判断是否存在两条长度奇偶性相同的从x走到p、从y走到q的路径 
(1)当a和b在一个是二分图的联通块中时，a到b所有路径长度奇偶性相同：进行二分图染色，同色点之间都是偶数、异色点之间都是奇数
(2)当a和b在一个存在奇环的联通块中时，a到b存在长度为奇数的路径、也存在长度为偶数的路径
(3)当(x, y)中有一个点是孤立点时，(x, y)单独成为一个联通块
根据(1)(2)(3)可以直接分类讨论计数
*/

#include <cstdio>

using namespace std;

namespace io
{
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush (){fwrite (obuf, 1, oS - obuf, stdout);oS = obuf;}
	inline void putc (char x){*oS ++ = x;if (oS == oT) flush ();}
	template <class I>
	inline void gi (I &x) {for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;}
	template <class I>
	inline void print (I x){
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;while(x) qu[++ qr] = x % 10 + '0',  x /= 10;while (qr) putc (qu[qr--]);}
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io::gi;
using io::putc;
using io::print;

typedef long long int LL;
const int Max_N(100050);
const int Max_M(200050);

int N, M, Head[Max_N], Total, To[Max_M << 1], Next[Max_M << 1];

inline void Add_Edge(int s, int t)
{
	++Total, To[Total] = t, Next[Total] = Head[s], Head[s] = Total;
}

int color[Max_N], A, B, C, V;
LL Ans;
bool qaq;

void dfs(int u)
{
	++V;
	for (int i = Head[u], v;i;i = Next[i])
		if (!color[v = To[i]])
			color[v] = 3 - color[u], dfs(v);
		else
			if (color[v] == color[u])
				qaq = true;
}

int main()
{
	gi(N), gi(M);
	for (int u, v;M--;)
		gi(u), gi(v), Add_Edge(u, v), Add_Edge(v, u);
	for (int u = 1;u <= N;++u)
	{
		if (color[u])
			continue;
		if (color[u] = 1, V = 0, qaq = false, dfs(u), qaq == false)
			if (V > 1)
				Ans += (A * 2 + B) * 2 + 2, ++A;
			else
				++C;
		else
			Ans += (A + B) * 2 + 1, ++B;
	}
	print(Ans + C * 1LL * N + N * 1LL * C - C * 1LL * C);
	return 0;
}