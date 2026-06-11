#include <iostream>

using namespace std;

int main()
{
	long long k;
	cin >> k;
	cout << 50 << endl;
	if(k <= 50)
	{
		for(int i = 1; i <= k; i ++)
		{
			cout << 50 << " ";
		}
		for(int i = k + 1; i <= 50; i ++)
		{
			cout << 0 << " ";
		}
	}
	else
	{
		long long a = k % 50, b = k / 50;
		for(int i = 1; i <= a; i ++)
		{
			cout << 50 + b << " ";
		}
		for(int i = a + 1; i <= 50; i ++)
		{
			cout << 50 + b - a - 1 << " ";
		}
	}
	return 0;
}