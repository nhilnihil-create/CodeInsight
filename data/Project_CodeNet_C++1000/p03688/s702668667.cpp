#include<bits/stdc++.h>
using namespace std;
int n, mn = 1000000, mx, cnt;
int read()
{
	int num = 0;
	char c = getchar();
	while (c < '0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		int num = read();
		if (num < mn)mn = num, cnt = 1;
		else if (num == mn)cnt++;
		mx = max(mx, num);
	}
	if (mx - mn > 1)
	{
		cout << "No" << endl;
		return 0;
	}
	if (mx == mn)
	{
		if (mx == n - 1)
			cout << "Yes" << endl;
		else if (2 * mx <= n)
			cout << "Yes" << endl;
		else cout << "No" << endl;
		return 0;
	}
	if (mn >= cnt && 2 * (mx - cnt) <= n - cnt)
		cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}