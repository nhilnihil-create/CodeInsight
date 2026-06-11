#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll a[N];
int main()
{
	ll n,m,i,j,k,s,t,sum,l,r;
      scanf("%lld",&n);
	{
		sum=0;
		for(i=1;i<=n;i++)
		scanf("%lld",&a[i]),sum+=a[i];
		l=a[1];
		m=1E15;
		for(i=2;i<=n;i++)
		 {
		 	r=sum-l;
		 	ll rs=llabs(l-r);
		 	m=min(m,rs);
		 	l+=a[i];
		 }
		 printf("%lld\n",m);
	}
	return 0;
}