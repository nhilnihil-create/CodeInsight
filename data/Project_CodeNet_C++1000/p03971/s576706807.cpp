#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	int total = a + b;
	for (int i = 0; i < n; i++)
	{
		if (total <= 0 || s[i] == 'c')
		{
			cout << "No" << '\n';
		}
		else if (s[i] == 'a')
		{
			cout << "Yes" << '\n';
			total--;
		}
		else
		{
			if (b > 0)
			{
				cout << "Yes" << '\n';
				b--;
				total--;
			}
			else
			{
				cout << "No" << '\n';
			}
		}
	}
	return (0);
}
