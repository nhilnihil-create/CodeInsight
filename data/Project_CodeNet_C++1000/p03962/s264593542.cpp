#include <iostream>
#include <string>
#include<math.h>
using namespace std;

int main()
{

int a, b, c;
	cin >> a >> b >> c;
	if ((a != b&&a==c)||(a==b&&a!=c)||(b==c&&c!=a))
		cout << 2 << endl;
	else if (a != b&&a != c&&b != c)
		cout << 3 << endl;
	else if (a == b&&a == c)
		cout << 1 << endl;


    return 0;
}
