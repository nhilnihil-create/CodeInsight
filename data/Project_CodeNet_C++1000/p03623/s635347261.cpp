#include<iostream>
using namespace std;
int main()
{
	int x, a, b;
	cin >> x >> a >> b;
	int y = x - a;
	int z = x - b;
	if (y < 0)
    	y = y * -1;
	if (z < 0)
		z = z * -1;
	if (y < z)
		cout << "A" ;
	else
		cout << "B";

	return 0;
}