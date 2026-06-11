#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
	int a, b, c, min = 30000;
	cin >> a >> b >> c;
	if( min > a + b )
		min = a + b;
	if( min > a + c )
		min = a + c;
	if( min > c + b )
		min = c + b;
	cout << min;
	return 0;
}