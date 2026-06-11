#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
const int N = 2e5 + 5;
const int mod = 1e9 + 7; 
using namespace std;

int n, prm[N], cnt, sum[N], ans, vis[N]; 

template < typename T >
inline T read()
{
	T x = 0, w = 1; char c = getchar();
	while(c < '0' || c > '9') { if(c == '-') w = -1; c = getchar(); }
	while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * w; 
}

void init()
{
	for(int i = 2; i <= n; i++)
	{
		if(!vis[i]) vis[i] = 1, prm[++cnt] = i;
		for(int j = 1; i * prm[j] <= n; j++)
		{
			vis[i * prm[j]] = 1;
			if(i % prm[j] == 0) break; 
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("cpp.in", "r", stdin); 
#endif
	n = read <int> (), init();
	for(int tmp, i = 2; i <= n; i++)
	{
		tmp = i;
		for(int j = 1; j <= cnt && prm[j] <= i; j++)
			if(!(tmp % prm[j])) while(tmp % prm[j] == 0) sum[prm[j]]++, tmp /= prm[j]; 
	}
	ans = 1;
	for(int i = 1; i <= n; i++) ans = 1ll * ans * (sum[i] + 1) % mod;
	printf("%d\n", ans); 
	return 0; 
}
