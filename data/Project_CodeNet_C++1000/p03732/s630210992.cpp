#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 1010, M = 1010;

int n, m;
map<int, int> f[2];

int main()
{
	scanf("%d%d", &n, &m);
	
	int t = 1;
	f[0][0] = 0;
	for (int i = 1; i <= n; i ++ , t ^= 1)
	{
		int w, v;
		scanf("%d%d", &v, &w);
		
		for (auto u : f[t ^ 1])
		{
			f[t][u.F] = max(f[t][u.F], u.S);
			if (u.F + v <= m) f[t][u.F + v] = max(f[t][u.F + v], u.S + w);
		}
	}
	
	int res = 0;
	for (auto u : f[t ^ 1]) res = max(res, u.S);
			
	printf("%d\n", res);
	return 0;
}