#include <iostream>
using namespace std;

int main()
{
	long long q, h, s, d, n;
	cin >>q >>h >>s >>d >>n;

	long long hp = min(h, 2 * q);
	long long sp = min(s, 2 * hp);
	long long dp = min(d, 2 * sp);

	long long cost = (n / 2) * dp;
	if(n % 2 == 1)
		cost += sp;
	cout <<cost <<"\n";
	return 0;
}
