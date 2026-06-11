#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0)cout << 0 << endl;
	else
	{
		int d = max(a, max(b, c));
		if (d == a)
			cout << b * c << endl;
		else if (d == b)
			cout << a * c << endl;
		else 
			cout << b * a << endl;
	}
}