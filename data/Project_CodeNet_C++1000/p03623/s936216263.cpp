#include <iostream>
#include <cmath>
using namespace std;
typedef long long int LLI;
int main()
{
	int x, a, b;
	cin >> x >> a >> b;
	if( abs( x - a ) > abs( x - b ) )
		cout << "B";
	else
		cout << "A";
}