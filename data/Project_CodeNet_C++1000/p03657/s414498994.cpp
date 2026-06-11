#include<iostream>
using namespace std;

int main()
{
	int a, b, x;
	cin >> a >> b;
	x = a + b;
	if (x % 3 == 0)
		cout << "Possible";
	else if (a % 3 == 0 || b % 3 == 0)
		cout << "Possible";
	else
		cout << "Impossible";

	
}