#include<bits/stdc++.h>
using namespace std;
int n, num[100007];
int gcd(int a, int b)
{
	if (!b)return a;
	return gcd(b, a % b);
}
int read()
{
	int num = 0;
	char c = getchar();
	while (c < '0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num;
}
int solve()
{
	int cnt = 0;
	bool is = 0;
	for (int i = 1; i <= n; i++)
		if (num[i] == 1)
			is = 1;
		else if (num[i] % 2 == 0)cnt++;
	if (is)
		return cnt % 2;
	if (cnt % 2 == 1)
		return 1;
	if (n - cnt > 1)
		return 0;
	for (int i = 1; i <= n; i++)
		if (num[i] % 2 == 1)num[i]--;
	int g = num[1];
	for (int i = 2; i <= n; i++)
		g = gcd(g, num[i]);
	for (int i = 1; i <= n; i++)
		num[i] /= g;
	return solve() ^ 1;
}
int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		num[i] = read();
	cout << (solve()? "First" : "Second") << endl;
	return 0;
}