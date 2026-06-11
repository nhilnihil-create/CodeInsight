#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(LL a,LL b)
{
	return b?gcd(b,a%b):a;
}

int main()
{
	LL a,b;
	cin>>a>>b;
	LL ans=a;
	a-=b;
	while(true)
	{
		if(a<b) swap(a,b);
		if(a%b)
		{
			ans+=a/b*b*2;
			a%=b;
		}
		else
		{
			ans+=(a/b*2-1)*b;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}