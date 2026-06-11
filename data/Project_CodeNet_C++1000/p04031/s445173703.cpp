#include <iostream>

using namespace std;

int a[101];

float avg(int * a, int n)	{
	float mean = 0;
  	for (int i = 0; i < n; i++)	{
    	mean += a[i];
    }
  	mean /= n;
  	return mean;
}

int main()	{
  	int n;
  	cin >> n;
  	int int_mean = 0;
  	for (int i = 0; i < n; i++)	{
    	cin >> a[i];
    }
  	float mean = avg(a, n);
  	if (mean < 0)	{
    	int_mean = mean - 0.5;
    }
  	else	{
    	int_mean = mean + 0.5;
    }
  	long long result = 0;
  	for (int i = 0; i < n; i++)	{
    	result += (a[i] - int_mean) * (a[i] - int_mean);
    }
  	cout << result << endl;
  	return 0;
}