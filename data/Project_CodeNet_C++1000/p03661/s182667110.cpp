#include<iostream>
#include<math.h>
using namespace std;

#define long_long_max 9223372036854775807

int main()
{
	int n;
	cin >> n;
	long long total = 0;
	long long *p = (long long*)malloc(n * sizeof(long long));
	long long *p1 = (long long*)malloc(n * sizeof(long long));
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		total = total + p[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (i != 0)
		{
			p1[i] = p1[i - 1] + p[i];
		}
		else
		{
			p1[i] = p[i];
		}
	}
	long long min = long_long_max;
	for (int i = 0; i < n - 1; i++)
	{
		if (abs(2 * p1[i] - total) < min)
		{
			min = abs(2 * p1[i] - total);
		}
	}
	cout << min << endl;
	free(p); free(p1);
	return 0;
}