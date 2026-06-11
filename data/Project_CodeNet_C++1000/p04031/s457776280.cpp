#include <iostream>
#include<algorithm>
int a[101];
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int m = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		if (a[0] == a[n - 1])
			cout << m << endl;
		else
		{
			m = 1e9;
			int x = 0;
			for (int i = a[0]; i < a[n - 1]; i++)
			{
				x = 0;
				for (int j = 0; j < n; j++)
				{
					x += (i - a[j]) * (i - a[j]);
				}
				if (x < m)
					m = x;
			}
			cout << m << endl;
		}
	}
}