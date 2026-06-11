#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200 + 5

int m, sz, cur, A[N], S[N];
LL n, C[N][N];
vector<int> Vec[N];

LL Calc(int l)
{
	return (1LL << (l - 1)) - 1;
}

void Prepare()
{
	for (int i = 0; i <= m; i ++)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; j ++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
}

int main()
{
	scanf("%lld", &n);
	
	for (m = 1; Calc(m) <= n; m ++) ;
	n -= Calc(-- m);
	cur ++, sz = m;
	for (int i = 1; i <= m; i ++)
	{
		A[i] = cur;
		Vec[i].push_back(cur);
	}
	
	Prepare();
	
	while (n > 0)
	{
		int mx = 0;
		for (int i = 1; i <= m; i ++)
			if (C[m][i] <= n && C[m][i] > C[m][mx])
				mx = i;
		cur ++, sz += 2;
		Vec[mx].insert(Vec[mx].begin() + (mx > 0 ? 1 : 0), cur);
		Vec[m].push_back(cur);
		n -= C[m][mx];
	}
	
	printf("%d\n", sz);
	for (int i = 0, j = 0; i <= m; i ++)
		for (int x : Vec[i])
			printf("%d%c", x, (++ j) == sz ? '\n' : ' ');
	return 0;
}