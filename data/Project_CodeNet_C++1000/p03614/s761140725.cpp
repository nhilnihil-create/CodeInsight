#include <bits/stdc++.h>
#pragma warning (disable : 4996)
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	int a[100007];
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == i+1)
		{
			if (i == n - 1) swap(a[i], a[i - 1]);
			else swap(a[i], a[i + 1]);
			cnt++;
		}
	}
	return !printf("%d", cnt);
}