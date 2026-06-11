#include <iostream>
using namespace std;
int main()
{
	long long int a, b, x, save_a, save_b;
	cin >> a >> b >> x;
	save_a = a / x;
	if( a % x != 0 )
		save_a++;
	save_b = b / x;
	if( save_a > save_b )
		cout << 0;
	else
		cout << save_b - save_a + 1;
}