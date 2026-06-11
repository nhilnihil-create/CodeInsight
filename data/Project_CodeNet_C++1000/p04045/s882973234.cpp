#include <iostream>

using namespace std;

int invalidDigit[10];
int res = 1 << 30;
int n;

void findMinNumber(int now)
{
	if (now >= n)
	{
		res = min(now, res);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (!invalidDigit[i])
		{
			if (now == 0 && i == 0)
			{
				continue;
			}

			findMinNumber(10 * now + i);
		}
	}
}

int main()
{	
	int k; cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x; cin >> x;
		invalidDigit[x] = true;
	}

	findMinNumber(0);

	cout << res;
	return 0;
}
