#include <iostream>
#include <string>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if ((a + b + c) % 17 == 0)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
}