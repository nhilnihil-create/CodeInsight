#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;

	if (a == 1 && b != 1)
		cout << "Alice";
	if (b == 1 && a != 1)
		cout << "Bob";
	if (a > b && b != 1 )
		cout << "Alice";
	if (b > a && a!= 1 )
		cout << "Bob";
	if (a == b)
		cout << "Draw";
	return 0;
}