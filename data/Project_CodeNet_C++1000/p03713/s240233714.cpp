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
const LL INF = 1e18;

LL n, m;

LL get1(LL n, LL m)
{
	LL res = INF;
	for (int i = 1; i < n; i ++ )
	{
		LL a = (n - i) / 2LL, b = n - i - a;
		LL area[] = {i * m, a * m, b * m};
		sort(area, area + 3);
		res = min(res, area[2] - area[0]);
	}
	return res;
}

LL get2(LL m, LL n)
{
	LL res = INF;
	for (int i = 1; i < n; i ++ )
	{
		LL a = m / 2, b = m - a, c = n - i;
		LL area[] = {a * c, b * c, i * m};
		sort(area, area + 3);
		res = min(res, area[2] - area[0]);
	}
	return res;
}

int main()
{
	cin >> n >> m;
	cout << min(min(get1(n, m), get1(m, n)), min(get2(n, m), get2(m, n)));
    return 0;
}