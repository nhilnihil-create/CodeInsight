#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> d(n);
	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
	}

	int c = 1, a = d[0];
	bool ok = true;
	while (a != 2)
	{
		a = d[a - 1];
		c++;
		if (c > n)
		{
			ok = false;
			break;
		}
	}
	if (ok)
		cout << c << endl;
	else 
		cout << -1 << endl;
}

