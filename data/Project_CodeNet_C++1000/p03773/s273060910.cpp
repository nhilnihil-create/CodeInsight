#include<iostream>
#include <math.h>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int x = a + b;
	if (x == 24)
		x = 00 ;
	if (x > 24)
		x = x - 24;
	cout << x ;
	return 0 ;
}