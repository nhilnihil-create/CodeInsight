#include<iostream>
using namespace std;
 
int main()
{
	int a, b, c,m,d;
	cin >> a >> b >> c;
	m = b - a;
	d = c - b;
	if (m == d)
		cout << "YES";
	else
		cout << "NO";

}