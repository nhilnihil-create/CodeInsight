#include "stdio.h"
#include "iostream"
using namespace std;

int main()
{
	long int n, min, A, a[200001], sum = 0;
	cin >> n;
	for (long i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	A = a[1];
	if (sum - 2 * A >= 0)
		min = sum - 2 * A;
	else min = 2 * A - sum;
	for (long i = 1; i < n; i++) {
		if (sum - 2 * A <= min && sum - 2 * A >= 0)
			min = sum - 2 * A;
		else if (sum - 2 * A <= 0 && min >= 2 * A - sum)
		{
			min = 2 * A - sum;
		}
		A += a[i + 1];
	}
	cout << min;
}

