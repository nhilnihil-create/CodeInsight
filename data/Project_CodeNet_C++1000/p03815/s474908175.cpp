#include <iostream>
typedef long long int lli;
using namespace std;

int main(void)
{
	lli x; cin >> x;
	lli ans = (x / 11) * 2;
	if (x % 11 >= 7)ans += 2;
	else if (x % 11 >= 1)ans ++;

	cout << ans << endl;

	return 0;
}
