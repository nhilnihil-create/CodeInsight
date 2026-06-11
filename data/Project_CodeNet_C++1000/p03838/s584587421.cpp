#include <bits/stdc++.h>
using namespace std;

const int N = 500 + 5;

int main()
{
	int x, y;
	cin >> x >> y;
	if (x == y)
	{
		cout << 0 << endl;
	}
	else if (x < y)
	{
		if (x >= 0) cout << (y - x) << endl;
		else
		{
			if (y <= 0) cout << (y - x) << endl;
			else if (abs(x) == abs(y)) cout << 1 << endl;
			else if (abs(x) < abs(y)) cout << 1 + y + x << endl;
			else cout << abs(x) - abs(y) + 1 << endl;
		}
	}
	else
	{
		if (y >= 0) cout << 1 + min(y + x, abs(x) - abs(y) + 1);
		else if (x <= 0) cout << min(abs(x) + abs(y) + 1, 1 + abs(y) - abs(x) + 1) << endl;
		else if (abs(x) == abs(y)) cout << 1 << endl;
		else if (abs(x) < abs(y)) cout << abs(y) - abs(x) + 1 << endl;
		else cout << 1 + abs(x) - abs(y) << endl;
	}
	return 0;
}