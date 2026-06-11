#include <iostream>
#include<cmath>
using namespace std;
long long a[200000];

int main()
{
	int num;
	long long min, carnum;
	int i = 0;
	cin >> num;
	while ((i <= num - 1)&&cin >> carnum)
	{
		a[i + 1] = a[i] + carnum;
		++i;
	}
	min = abs(a[num] - a[1] - a[1]);
	for (int j = 2; j < num; j++)
	{
		if (abs(a[num] - a[j] - a[j])<min)
		min = abs(a[num] - a[j] - a[j]);
	}
	cout << min;
    return 0;
}