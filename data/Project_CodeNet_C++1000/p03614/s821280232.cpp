#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 10;

int a[N], b[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
		b[i] = (a[i] == i);
	}
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		if(b[i] == 1)
		{
			ans++;
			i++;
		}
	}
	cout << ans << endl;
}