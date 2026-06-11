#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 50 + 5;
ll f[2][maxn];
int main()
{
	int n, p;
	scanf("%d%d", &n, &p);
	f[0][0] = 1;
	for(int i = 1; i <= n; ++i)
	{
		int v;
		scanf("%d", &v);
		v %= 2;
		if(!v)
		{
			f[0][i] = f[0][i - 1] << 1;
			f[1][i] = f[1][i - 1] << 1;
		}
		else
		{
			f[0][i] = f[0][i - 1] + f[1][i - 1];
			f[1][i] = f[1][i - 1] + f[0][i - 1];
		}
	}
	cout << f[p][n] << endl;
	return 0;
}