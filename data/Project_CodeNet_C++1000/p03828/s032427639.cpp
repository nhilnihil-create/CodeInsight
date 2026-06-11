#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

int largestPower(int n, int p) 
{ 
	// Initialize result 
	int x = 0; 

	// Calculate x = n/p + n/(p^2) + n/(p^3) + .... 
	while (n) 
	{ 
		n /= p; 
		x += n; 
	} 
	return x; 
} 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<int> prime;
	prime.push_back(2);
	for(int i = 3; i<=n;i++)
	{
		int j=2;
		for(;j<i;j++)
			if(i%j==0)
				break;
		if(i==j)
			prime.push_back(i);
	}
	ll ans = 1;
	for(auto it:prime)
	{
		int g = largestPower(n,it);
		ans = ans *(g+1)%mod;
	}
	cout<<ans<<endl;
	return 0; 
}