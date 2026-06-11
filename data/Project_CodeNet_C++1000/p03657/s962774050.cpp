#include <iostream>
using namespace std ;
int main()
{
	int a, b;
	cin >> a >> b;
	int x = a + b;
	if ( x % 3== 0 || a % 3 == 0 || b % 3 ==0 )
		cout << "Possible";
	else
		cout << "Impossible";
	return 0;
}
