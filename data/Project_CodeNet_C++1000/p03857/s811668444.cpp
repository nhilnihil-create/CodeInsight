#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define SF scanf
#define PF printf
#define PC putchar

const int MAXN = 200005;

int n, K, L, fa[MAXN], father[MAXN];

int find1(int x) { return (father[x] == 0) ? x : father[x] = find1(father[x]); }
int find2(int x) { return (fa[x] == 0) ? x : fa[x] = find2(fa[x]); }

map<pair<int, int> , int> s;

int main ()
{
	int x, y;
	SF("%d%d%d", &n, &K, &L);
	for(int i = 1; i <= K; i++)
	{
		SF("%d%d", &x, &y);
		int xx = find1(x), yy = find1(y);
		if(xx != yy) father[yy] = xx;
	}
	for(int i = 1; i <= L; i++)
	{
		SF("%d%d", &x, &y);
		int xx = find2(x), yy = find2(y);
		if(xx != yy) fa[yy] = xx;
	}
	for(int i = 1; i <= n; i++) s[make_pair(find1(i), find2(i))]++;
	for(int i = 1; i <= n; i++) PF("%d ", s[make_pair(find1(i), find2(i))]);
}