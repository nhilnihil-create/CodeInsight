#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int x;
	cin >> x;
	for (long long i = 0;; i++)
	{
		if (i * (i + 1) / 2 >= x)
		{
			cout << i << endl;
			break;
		}
	}

	return 0;
}
