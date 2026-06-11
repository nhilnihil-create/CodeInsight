#include<iostream>
using namespace std;
int main()
{
	long long a, b;
	char c;
	cin >> a >> c >> b;
	long long ans = 0;
	if (c == '+')
		ans = a + b;
	else ans = a - b;
	cout << ans;
	return 0;
}