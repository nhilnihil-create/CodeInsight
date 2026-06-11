#include<iostream>
#include<cstdio>
#include<algorithm>
#define P 1000000007
#define ll long long
using namespace std;
ll n,a[100005];
int main()
{
	scanf("%lld",&n);
	for (ll i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll Ans=1,sum=0;
	for (ll i=1;i<=n;i++)
	{
	//	cout<<Ans<<' '<<sum<<endl;
		if (sum*2+1>a[i]+1)
			Ans=Ans*sum%P;
		else
		if (sum*2+1==a[i]+1) Ans=Ans*(sum+1)%P;
		else sum++;
	//cout<<Ans<<' '<<sum<<endl;
	}
	while(sum) Ans=Ans*(sum--)%P;
	printf("%lld\n",Ans);
}