#include <iostream>
#include <string>
using namespace std;
int main()
{
	string op;
	int a, b;
	cin >> a >> op >> b;
	if (op[0] == '+')
		cout << a + b << "\n";
	else
		cout << a - b << "\n";
}