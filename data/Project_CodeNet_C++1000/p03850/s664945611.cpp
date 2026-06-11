#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;

const int MAXN = 100000 + 1000;
const long long INF = 0x1f1f1f1f1f1f1f1fll;

int n, cur = 0;
long long f[2][3];

void update(char op, int val)
{
	cur ^= 1;

	f[cur][0] = f[cur ^ 1][0] + (op == '-' ? -1 : 1) * val;
	f[cur][1] = f[cur ^ 1][1] - (op == '-' ? -1 : 1) * val;
	f[cur][2] = f[cur ^ 1][2] + (op == '-' ? -1 : 1) * val;

	if(op == '-')
	{
		f[cur][1] = max(f[cur][1], f[cur ^ 1][0] - val);
		f[cur][2] = max(f[cur][2], f[cur ^ 1][1] + val);
	}

	f[cur][0] = max(f[cur][0], f[cur][1]);
	f[cur][0] = max(f[cur][0], f[cur][2]);
	f[cur][1] = max(f[cur][1], f[cur][2]);

	// cerr << f[cur][0] << ' ' << f[cur][1] << ' ' << f[cur][2] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	cin >> n;

	f[cur][0] = 0;
	f[cur][1] = f[cur][2] = -INF;

	char op[5] = {};
	int val;

	cin >> val;
	update('+', val);
	for(int i = 2; i <= n; i++)
	{
		cin >> op >> val;
		update(op[0], val);
	}
	long long ans = f[cur][0];
	cout << ans << endl;


	return 0;
}
