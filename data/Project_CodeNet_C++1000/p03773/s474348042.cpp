#include<iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int x = a + b;
	if (b == 0)
		cout << a;
	else if (x > 23)
		cout << x - 24;
	else
		cout << x;
}
