#include<iostream>
using namespace std;
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	while (1 <= (a && b && c) && (a && b && c) <= 10000)
	{
		if ((a+b) < (a+c) && (a+b) < (b+c))
			cout << a+b ;
		if ( (a+c) < (a+b) && (a+c) < (b+c) )
			cout << a+c ;
		if ((b+c) < (a+b) && (b+c) < (a+c))
			cout << b+c ;
		if ((a + b) && (a + c) == (b + c))
			cout << a + b ;
		break;
	}
	return 0; 
}