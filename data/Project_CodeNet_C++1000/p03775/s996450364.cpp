#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	ll m =20;
	cin>>n;
  	if(n==1)
    {
      cout<<1<<"\n";
      return 0;
    }
      
	for(int i=1;i<=sqrtl(n);i++)
	{
		if(n%i==0)
		{
			ll j=n/i;
			if(j%10==0)
				j += 10;
			if(i%10==0)
				i += 10;
			ll k = (ll)max(ceil((log(i))/log(10)),ceil((log(j))/log(10)));
			if(k<m)
				m=k; 
		}
	}
	cout<<m<<"\n";
}