#include <iostream>
using namespace std;
int main()
{
	int a[200010];
	long long int b[200010];
	int N = 2;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> a[i];
	}
	long long int sum = 0;
	long long int m, n;
	for(int j=1;j<=N;j++)
	{
		sum = sum + a[j];
	}
	m = sum;
	n = sum;
	long long int x[200009], y[200009];
	for (int j = 1; j <= (N - 1); j++)
	{
		y[j] = sum - a[j];
		sum = sum - a[j];
	}
	for (int k = 1; k <= (N - 1); k++)
	{
		x[k] = m - y[k];
		m = n;
	}
	for (int n = 1; n <= (N - 1); n++)
	{
		b[n] = abs(x[n] - y[n]);
	}
	long long int min = b[1];
	for (int i = 2; i <= N - 1; i++)
	{
		if (min > b[i])
			min = b[i];
	}
	cout << min<<endl;
	return 0;
}