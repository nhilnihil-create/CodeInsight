#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
#define mod 1000000007
typedef unsigned long long int ull;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ull n,p=1;
	cin>>n;
    for (ull i = 1; i <= n; i++)
	{
		p=(p%mod)*(i%mod);
		p%=mod;
	}
	cout<<p;
	
	

   return 0;
}
