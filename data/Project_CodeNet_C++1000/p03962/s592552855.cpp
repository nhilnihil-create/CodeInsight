#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int x = 3;
	if (a == b)
		x -= 1;
	if (b == c)
		x -= 1;
	if (a == c)
		x -= 1;
	if (x == 0)
		cout << "1" << "\n";
	else
		cout << x << "\n";
}