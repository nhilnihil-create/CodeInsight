#include <iostream>
using namespace std;
int main()
{
	string a, b, c;
  	int x = 'a'-'A';
  	cin >> a >> b >> c;
  	cout << (char)(a[0]-x) << (char)(b[0]-x) << (char)(c[0]-x);
}