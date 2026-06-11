#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#define N 1000005
#define mk(i, j) make_pair(i, j)
using namespace std;

int h, w, n, cnt[N], u[9] = { 0, 0, 0, 1, 1, 1, 2, 2, 2 }, v[9] = { 0, 1, 2, 0, 1, 2, 0, 1, 2 };
long long num[15]; 
map <pair<int, int>, int> mp; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

bool check(int x, int y, int xx, int yy)
{
	if(x < 1 || x > h || y < 1 || y > w) return 1;
	if(xx < 1 || xx > h || yy < 1 || yy > w) return 1;
	return 0; 
}

int main()
{
	h = read <int> (), w = read <int> (), n = read <int> ();
	num[0] = 1ll * (h - 2) * (w - 2);
	for(int x, y, id, i = 1; i <= n; i++)
	{
		x = read <int> (), y = read <int> ();
		for(int j = 0; j < 9; j++)
		{
			if(check(x + u[j], y + v[j], x + u[j] - 2, y + v[j] - 2)) continue; 
			if(!mp[mk(x + u[j], y + v[j])])
				mp[mk(x + u[j], y + v[j])] = ++cnt[0]; 
			id = mp[mk(x + u[j], y + v[j])];
			num[cnt[id]]--; num[++cnt[id]]++; 
		}
	}
	for(int i = 0; i <= 9; i++)
		printf("%lld\n", num[i]); 
	return 0; 
}
