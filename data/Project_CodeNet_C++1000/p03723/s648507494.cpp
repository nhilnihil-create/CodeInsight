#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;

long long int gcd(long long int x, long long int y)
{
	if (y == 0) { return x; }
	return gcd(y, x % y);
}

int function(int a, int b, int c) 
{
	if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1)
	{
		return 0;
	}
	if (a == b && b == c)
	{
		return -1;
	}

	return function((a + b) / 2, (b + c) / 2, (c + a) / 2) + 1;
}

int main(void)
{
	long long int a, b, c,count = 0;
	cin >> a >> b >> c;
	int ans = function(a, b, c);

	cout << ans << endl;
	return 0;
}
