#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
int main()
{
	int n,x,k(0);ll ans(1);
	cin>>n;
	for(register int i(1);i <= n;i++)
	{
		scanf("%d",&x),++k;
		if(x < (k << 1) - 1) {ans *= k,--k;if(ans >= mod) ans %= mod;}
	}
	while(k) {ans *= k,--k;if(ans >= mod) ans %= mod;}
	cout<<ans; 
	return 0;
}