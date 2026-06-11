#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	long long int a, b, c, ans;
	cin >> a >> b >> c;
	if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0)
		cout << 0;
	else
	{
		if (a >= b && a >= c)
				ans = b * c;
		else if (b >= a && b >= c)
				ans = a * c;
		else if (c >= a && c >= b)
				ans = a * b;
		cout << ans;
	}
	return 0;
}