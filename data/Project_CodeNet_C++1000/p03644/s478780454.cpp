#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
	int x, tmp = 1;
	cin >> x;
	while( tmp <= x )
		tmp *= 2;
	cout << tmp / 2;
}