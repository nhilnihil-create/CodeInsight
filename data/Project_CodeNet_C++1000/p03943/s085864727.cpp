#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int x;
	if (a > b) {
		if (a > c)
			x = a;
		else
			x = c;
	}
	else if (b > c)
		x = b;
	else
		x = c;
	if (x == a + b + c - x)
		cout << "Yes" << "\n";
	else
		cout << "No" << "\n";
}