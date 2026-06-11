#include <iostream>
#include <cmath>
#define mod 1000000007
using namespace std;
typedef long long int LLI;
LLI solve(LLI & a, LLI & b)
{
	LLI ans = 1, smaller = a > b ? b : a, bigger = a > b ? a : b;
	for(LLI i = 1; i <= smaller; i++)
	{
		ans *= (i*i)%mod;
		ans %= mod;
	}
	if( a == b )
		return ( 2 * ans ) % mod;
	return ( bigger * ans ) % mod;
}

int main()
{
	LLI a, b;
	cin >> a >> b;
    if( abs( a - b ) > 1 )
    	cout << 0;
    else
		cout << solve(a,b);
}