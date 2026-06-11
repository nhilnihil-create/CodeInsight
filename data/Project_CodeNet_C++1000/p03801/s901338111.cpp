#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
typedef long long ll; 
using namespace std;

int n, lst;
struct node { int v, id; } p[N]; 
ll ans[N]; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

bool cmp(node a, node b) { return a.v > b.v; }

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cpp.in", "r", stdin); 
#endif
	n = read <int> ();
	for(int i = 1; i <= n; i++) p[i].v = read <int> (), p[i].id = i;
	sort(p + 1, p + n + 1, cmp);
	for(int lst = INF, j = 1, i = 1; i <= n; i = j)
	{
		while(j <= n && p[j].v == p[i].v) lst = min(lst, p[j].id), j++; 
		ans[lst] += 1ll * (p[i].v - p[j].v) * (j - 1); 
	}
	for(int i = 1; i <= n; i++) printf("%lld\n", ans[i]); 
	return 0; 
}
