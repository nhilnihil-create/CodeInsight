#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

int n, m;
int v[N], w[N];
map<int, int> f[2];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];
	
	int t = 1;
	f[t][0] = 0;
	for (int i = 1; i <= n; i ++ )
	{
		t ^= 1;
		for (auto u : f[t ^ 1])
		{
			f[t][u.F] = max(f[t][u.F], u.S);
			if (u.F + v[i] <= m) f[t][u.F + v[i]] = max(f[t][u.F + v[i]], u.S + w[i]);
		}
	}
	
	int res = 0;
	for (auto u : f[t]) res = max(res, u.S);
	cout << res << endl;
    return 0;
}