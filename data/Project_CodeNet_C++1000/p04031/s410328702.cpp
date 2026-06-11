#include<bits/stdc++.h>
using namespace std;

int a[105];
int n;
int ans, ans2;

int f(int x)
{
	return x * x;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cnt += a[i];
	}
	if (cnt % n == 0)
	{
		int aver = cnt / n;
		for (int i = 1; i <= n; i++) ans += f(a[i] - aver);
		cout << ans << endl;
	}
	else
	{
		int aver = cnt / n;
		for (int i = 1; i <= n; i++) ans += f(a[i] - aver);
		aver++;
		for (int i = 1; i <= n; i++) ans2 += f(a[i] - aver);
		cout << min(ans, ans2) << endl;
	}
	return 0;
}
