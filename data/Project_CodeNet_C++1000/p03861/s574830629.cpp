#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
long long x, y, d;
	cin >> x >> y >> d;
    long long a;
    a = y / d;
	long long  b;
	b = (x == 0 ? -1 : (x - 1) / d);
	cout << a - b << endl;
	return 0;
}