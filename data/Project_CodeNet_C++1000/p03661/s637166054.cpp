#include<iostream>
using namespace std;
int a[200000];
long long int sum[200000];
long long int d[200000];
int main()
{
	int i;
	long long int j;
	long long int c;
	long long int b=0;
	cin >> i;
	for (int k=0; k < i; k++)
	{
		cin >> a[k];
		b = b + a[k];
	}
	sum[0] = a[0];
	for (int k = 1; k < i; k++)
	{
		sum[k] = sum[k - 1] + a[k];
		c = b - sum[k-1];
		d[k] = sum[k-1] - c;
	}
	j = abs(d[1]);
	for (int k = 1; k < i - 1; k++)
	{
		if (abs(d[k]) < j)
		{
			j = abs(d[k]);
		}
	}
	cout << j;
}