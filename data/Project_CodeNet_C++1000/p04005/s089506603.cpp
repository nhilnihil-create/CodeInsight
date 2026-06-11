#include<iostream>
using namespace std;
long long a, b, c, ab, bc, ac;
long long mins;
int main()
{
	cin >> a >> b >> c;
	ab = a * b;
	mins = ab;
	bc = b * c;
	if (bc < mins)
		mins = bc;
	ac = a * c;
	if (ac < mins)
		mins = ac;
	if (mins == ab)
	{
		long long temp;
		temp = (c - c / 2) - c / 2;
		temp = temp * ab;
		cout << temp;
		return 0;
	}
	if (mins == bc)
	{
		long long temp;
		temp = (a - a / 2) - a / 2;
		temp = temp * bc;
		cout << temp;
		return 0;
	}
	if (mins == ac)
	{
		long long temp;
		temp = (b - b / 2) - b / 2;
		temp = temp * ac;
		cout << temp;
		return 0;
	}
	return 0;
}