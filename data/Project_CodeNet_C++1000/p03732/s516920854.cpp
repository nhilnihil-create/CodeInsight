#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010, M = 110;

int n, m;
map<int, int> f[2];

int main()
{
	scanf("%d%d", &n, &m);
	
	int t = 0;
	f[t][0] = 0;
	for (int i = 1; i <= n; i ++ )
	{
		int w, v;
		scanf("%d%d", &w, &v);
		
		t ^= 1;
		for (auto u : f[t ^ 1])
		{
			f[t][u.F] = max(f[t][u.F], u.S);
			if (u.F + w <= m) f[t][u.F + w] = max(f[t][u.F + w], u.S + v);
		}
	}
	
	int res = 0;
	for (auto u : f[t]) res = max(res, u.S);
	printf("%d\n", res);
	return 0;
}