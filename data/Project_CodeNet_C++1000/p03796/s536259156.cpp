#include <iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
#define mod 1000000007
int main()
{

	long long n,f=1; cin >> n;
	for (int i = 1; i < n; ++i)
	{
		f =(f* i)%mod;
	}
	cout << (f*n)%mod;
}

