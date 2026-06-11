#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long a, b, c;

	cin >> a >> b >> c;

	//Keep a>b>c
	if (a < b)
		swap(a, b);
	if (a < c)
		swap(a, c);
	if (b < c)
		swap(b, c);

	if (a % 2)//最大边为奇数
	{
		cout << b * c << endl;
	}
	else
		cout << 0 << endl;
}