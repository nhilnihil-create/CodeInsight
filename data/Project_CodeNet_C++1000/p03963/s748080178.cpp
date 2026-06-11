#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n,k,c=1,d;
	cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		c=c*(k-1);
	}
	cout<<c*k;
}