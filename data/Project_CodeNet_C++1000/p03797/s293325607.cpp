#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll g = m/2;
	if(g>n)
	{
		ll y = (g-n)/2;
		n+=y;
	}
	cout<<min(n,g)<<endl;
	return 0;
}