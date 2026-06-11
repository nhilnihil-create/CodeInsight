#include <iostream>
using namespace std;
int main()
{
	long int n, a, sum = 0, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		if (a % 2 == 0)
		{
			sum++;
		}
		else
		{
			ans++;
		}
	}
	if(ans % 2 == 1)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl;
	}
	return 0;
}