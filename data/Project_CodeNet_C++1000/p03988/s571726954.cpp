#include <bits/stdc++.h>
using namespace std;
const int N = 103;
int a[N], cnt[N];
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	int d = a[n];
	for(int i = 1; i <= n; i++)
	{
		if(a[i] < (d + 1)/2)
		{
			// cout << "1 ";
			return cout << "Impossible\n", 0;
		}
		cnt[a[i]]++;
	}
	int x = 2;
	if(d % 2 == 0)
		x--;
	if(cnt[(d + 1)/2] != x)
	{
		// cout << "2 ";
		return cout << "Impossible\n", 0;
	}
	for(int i = (d + 1)/2 + 1; i <= d; i++)
	{
		if(cnt[i] < 2)
		{
			// cout << "3 ";
			return cout << "Impossible\n", 0;
		}
	}
	cout << "Possible\n";
}