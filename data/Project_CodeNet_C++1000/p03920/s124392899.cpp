#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll largest_element(ll n)
{
	if(n==1)
		return 1;
	ll low=0;
	ll high=n;
	while(low<high)
	{
		ll mid = low + (high - low)/2;
		if(mid*(mid+1)/2 >=  n)
		{
			high = mid;
		}
		else
		{
			low = mid+1;
		}
	}
	return low;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll n;
	cin>>n;
	while(n>0)
	{
		cout<<largest_element(n)<<'\n';
		n-=largest_element(n);
	}
}