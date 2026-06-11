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

int main(void)
{
	int a, b, h;
	cin >> a >> b >> h;
	cout << (a + b) * h / 2 << endl;
	return 0;
}
