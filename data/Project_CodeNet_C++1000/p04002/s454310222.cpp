/*--------------------------------
  Author: The Ace Bee
  Blog: www.cnblogs.com/zsbzsb
  This code is made by The Ace Bee
--------------------------------*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <ctime>
#include <map>
#define rg register
using namespace std;
template < typename T > inline void read(T& s) {
	s = 0; int f = 0; char c = getchar();
	while (!isdigit(c)) f |= (c == '-'), c = getchar();
	while (isdigit(c)) s = s * 10 + (c ^ 48), c = getchar();
	s = f ? -s : s;
}

typedef long long LL;
typedef pair < int, int > pii;
const int _ = 100010;

int n, m, k; LL ans[11];
map < pii, int > _map;
struct node{ int x, y; }a[_];

inline bool cmp(const node& n, const node& m)
{ return n.x == m.x ? n.y < m.y : n.x < m.x; }

int main() {
	read(n), read(m), read(k);
	for (rg int i = 1; i <= k; ++i)
		read(a[i].x), read(a[i].y);
	
	ans[0] = max(0ll, 1ll * (n - 2) * (m - 2));
	
	sort(a + 1, a + k + 1, cmp);
	/*
	for (rg int i = 1; i <= k; ++i)
		printf("%d %d\n", a[i].x, a[i].y);
//	*/
	pii p;
	for (rg int i = 1; i <= k; ++i)
		for (rg int x = max(1, a[i].x - 2); x <= min(n - 2, a[i].x); ++x)
			for (rg int y = max(1, a[i].y - 2); y <= min(a[i].y, m - 2); ++y)
				p = make_pair(x, y), --ans[_map[p]], ++_map[p], ++ans[_map[p]];
	
	for (rg int j = 0; j < 10; ++j) printf("%lld\n", ans[j]);
	
	return 0;
}
