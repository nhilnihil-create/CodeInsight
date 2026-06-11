#include<iostream>
#include<cmath>

using namespace std;
const int M = 2e5;
long long a[M];
long long sum[M];
int main()
{
	int n;
	while (cin >> n)
	{
		long long s = 0;
		sum[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			sum[i] = sum[i - 1] + a[i];
			s += a[i];
		}

		long long Min = abs(2 * sum[1] - s);
		for (int i = 1; i<n; i++)
		{
			if (Min > abs(2 * sum[i] - s))
				Min = abs(2 * sum[i] - s);
		}
		cout << Min << endl;
	}

	return 0;
}