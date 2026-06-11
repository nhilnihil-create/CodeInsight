#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll sum, x, n;
void gcd(ll x, ll y)
{
	if (y == 0) 
	{
		sum -= x; 
		return;
	}
	sum += x / y * y * 2;
	gcd(y, x % y);
}

int main()
{
	scanf("%lld%lld", &n, &x);
	gcd(x, n - x);
	cout << sum + n << endl;
}