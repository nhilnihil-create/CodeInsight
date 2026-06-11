#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
	int x, t;
	cin >> x >> t;
	if( t >= x )
		cout << 0;
	else	cout <<  x - t;
	return 0;
}