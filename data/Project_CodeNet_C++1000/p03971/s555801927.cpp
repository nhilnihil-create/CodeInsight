#include <bits/stdc++.h>
using namespace std;

int main()
{
	int64_t n, a, b;
	string s;
	cin >> n >> a >> b >> s;

	int64_t x = 0, y = 0;

	for (auto &&c : s)
	{
		if (c == 'a')
		{
			if (x < a + b)
			{
				cout << "Yes" << endl;
				x++;
			}
			else
			{
				cout << "No" << endl;
			}
		}
		else if (c == 'b')
		{
			if (x < a + b && y < b)
			{
				cout << "Yes" << endl;
				x++;
				y++;
			}
			else
			{
				cout << "No" << endl;
			}
		}
		else if (c == 'c')
		{
			cout << "No" << endl;
		}
	}

	return 0;
}