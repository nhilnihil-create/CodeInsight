#include<iostream>
#include<cmath>
using namespace std;
long long a[200005];
long long b[200005];
int main()
{
	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i == 0)
			b[i] = a[i];
		else
			b[i] = b[i - 1] + a[i];
		sum = sum + a[i];
	}
	long long min;
	if (b[0] > sum - b[0])
		min = 2 * b[0] - sum;
	else
		min = sum - (2 * b[0]);
	for (int i = 1; i < (n - 1); i++)
	{
		if (min > abs(sum - (2 * b[i])))
			min = abs(sum - (2 * b[i]));
	}
	cout << min << endl;
	return 0;
}
		