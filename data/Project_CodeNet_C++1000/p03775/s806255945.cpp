#include<iostream>
#include<string>
using namespace std;
typedef long long ll;

int main()
{
	ll n;
	cin >> n;
	int r = -1;
	for (int i = 1;i <= sqrt(n);i++)
	{
		if (n % i == 0) r = i;
	}
	r = n / r;
	int g = 0;
	while (r > 0)
	{
		g++;
		r /= 10;
	}
	cout << g;
}