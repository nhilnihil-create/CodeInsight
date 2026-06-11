#include <iostream>
#include <string>
using namespace std;
int main()
{
	string a, b;
	cin >> a >> b;
	if (a == "H")
		cout << b << "\n";
	else if (b == "H")
		cout << "D" << "\n";
	else
		cout << "H" << "\n";
}