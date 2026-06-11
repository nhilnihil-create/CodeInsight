#include <iostream>
using namespace std;
int main()
{
	long long a, b, c = 0;
	cin >> a >> b;
	cout << min(a,b/2)+max(b-a*2,c)/4;
	return 0;
}