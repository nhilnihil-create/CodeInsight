#include<iostream>
using namespace std;

int main()
{
	
	int a, b, c ,x,y,z;
	cin >> a >> b >> c;
	x = a + b;
	y = a + c;
	z = b + c;

	if (x<y&&x<z )
		cout << x;
	else if (y<x  && y<z)
		cout << y;
	else
		cout << z;
		
	
}