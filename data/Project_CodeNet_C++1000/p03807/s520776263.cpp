#define alphanso                  \
	ios_base::sync_with_stdio(0); \
	cin.tie(NULL)
#include <bits/stdc++.h>
using namespace std;
int main()
{
	alphanso;
	int n, i, x, flag = 0;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> x;
		if (x & 1)
			flag++;
	}
	flag & 1 ? cout << "NO" : cout << "YES";
	return 0;
}