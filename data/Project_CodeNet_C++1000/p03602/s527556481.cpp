#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int main()
{
	long long int floyd[400][400];
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%lld", &floyd[i][j]);
	for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (floyd[i][j] > floyd[i][k] + floyd[k][j]) return !printf("-1");
	long long int cnt = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < n && j!=i; j++)
	{
		bool flag = false;
		for (int k = 0; k < n; k++)
		{
			if (k == i || k == j) continue;  flag |= (floyd[i][j] == floyd[i][k] + floyd[k][j]);
		}
		if (!flag) cnt += floyd[i][j];
	}
	return !printf("%lld", cnt);
}