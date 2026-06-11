#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	ll ct = 0;
	ll rank = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'a')
		{
			if (ct < a + b)
			{
				cout << "Yes\n";
				ct++;
			}
			else
				cout << "No\n";
		}
		else if (s[i] == 'b')
		{
			rank++;
			if (ct < a + b && rank <= b)
			{
				cout << "Yes\n";
				ct++;
			}
			else
				cout << "No\n";
		}
		else
			cout << "No\n";
	}
	return 0;
}
