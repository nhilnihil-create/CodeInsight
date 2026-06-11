#include <bits/stdc++.h>
using namespace std;
#define MOD (long long int)(1e9+7)
#define ll long long int

ll mpow(ll a, ll b){
	if(b==0){
		return 1;
	}else if(b%2==0){
		ll memo = mpow(a,b/2);
		return memo*memo%MOD;
	}else{
		return mpow(a,b-1)*a%MOD;
	}
}
int main()
{   
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int c=0;
	if(n%2)
	{
		if(a[0]==!0)
		{
			cout<<0<<endl;
			return 0;
		}
		for(int i=1;i<n;i+=2)
		{
			if(a[i]!=i+1 || a[i+1]!=i+1)
				{
					cout<<0<<endl;
					return 0;
				}
				c++;
		}
	}
	else
	{
		for(int i=0;i<n;i+=2)
		{
			if(a[i]!=i+1 || a[i+1]!=i+1)
			{
				cout<<0<<endl;
				return 0;
			}
			c++;
		}
	}
	cout << mpow(2,c) << endl;
return 0;
}