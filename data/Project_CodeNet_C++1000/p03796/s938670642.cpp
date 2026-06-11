#include <iostream>
using namespace std;
 
int main()
{
	const long long MOD = 1000000007;
    long long n,f=1;
    cin >> n;
    for(long long i = 2; i <= n; i++)
	{
        f *= i;
        f %= MOD;
    }
    cout << f << endl;
	
    return 0;
}