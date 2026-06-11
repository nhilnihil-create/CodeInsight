#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"

int32_t main()
{
	IOS;
	string a, b, c;
	cin >> a >> b >> c;
	//int p = a.size(), q = b.size(), r = c.size();
	//p++, q++, r++;
	char x = a[0];
	//p--;
	a.erase(a.begin());
	while (1)
	{
		if (x == 'a')
		{
			x = a[0];
			//p--;
			if (a.size())
				a.erase(a.begin());
			else
			{
				cout << "A" << endl;
				return 0;
			}
		}
		else if (x == 'b')
		{
			x = b[0];
			//q--;
			if (b.size())
				b.erase(b.begin());
			else
			{
				cout << "B" << endl;
				return 0;
			}
		}
		else
		{
			x = c[0];
			//r--;
			if (c.size())
				c.erase(c.begin());
			else
			{
				cout << "C" << endl;
				return 0;
			}
		}
	}
	// if (p == 0)
	// 	cout << "A" << endl;
	// else if (q == 0)
	// 	cout << "B" << endl;
	// else
	// 	cout << "C" << endl;

	return 0;
}