#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
	ll a,b,c,cnt=0;
	cin>>a>>b>>c;
	while(a%2==0 && b%2==0 && c%2==0)
	{
		if(a==b && b==c)
		{
			cout<<-1;
			return 0;
		}
		ll a1=a,b1=b,c1=c;
		a=(b1+c1)/2;
		b=(a1+c1)/2;
		c=(a1+b1)/2;
		cnt++;
	}
	cout<<cnt;	
}