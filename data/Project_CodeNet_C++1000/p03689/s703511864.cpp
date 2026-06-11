#include <iostream>
#include <algorithm>

#define ll long long
using namespace std;

int main()
{
	int h, w, x, y;
	cin >> h >> w >> x >> y;
	if (h % x == 0 && w % y == 0)cout << "No" << endl;
	else
	{
		cout << "Yes" << endl;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (j > 0)cout << " ";
				cout << ((i+1) % x == 0 && (j+1) % y == 0 ? -(x * y - 1) * 1000 - 1 : 1000);
			}
			cout << endl;
		}
	}
	return 0;
}
