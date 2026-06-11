#include<iostream>
using namespace std;
long long a[100010],T,n,tot,s,tt;
int main()
{
	cin>>n;s=n*(n+1)/2;
	for(int i=1;i<=n;i++) cin>>a[i],tot+=a[i];
	if(tot%s!=0) return puts("NO"),0;
	T=tot/s;a[n+1]=a[1];
	for(int i=1;i<=n;i++)
		if((T+a[i]-a[i+1])%n||T+a[i]-a[i+1]<0)
			return puts("NO"),0;
		else tt+=(T+a[i]-a[i+1])/n;
	tt==T?puts("YES"):puts("NO");
}
