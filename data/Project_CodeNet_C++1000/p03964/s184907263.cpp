#include<bits/stdc++.h>
#define mod 1000000007
#define ll unsigned long long
#define ld long double
#define ar array
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	ll a=1,b=1;
	while(n--)
	{
		ld x,y;
		cin>>x>>y;
		ll n = max(ceil(a/(x)),ceil(b/(y)));
		a = n*x;
		b = n*y;
	}
	cout<< a+b <<endl;
	return 0;
}