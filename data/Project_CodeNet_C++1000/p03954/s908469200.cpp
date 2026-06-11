#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[200005],l,r,i,f[200005],p;
bool check(int y)
{
	for(i=1;i<=2*n-1;++i)
		if(a[i]<=y)
			f[i]=0;
		else
			f[i]=1;
	if(f[n]==f[n+1]||f[n]==f[n-1])
		return f[n];
	for(i=n;i<2*n-1;++i)
		if(f[i]==f[i+1])
			break;
	int ansr=i;
	for(i=n;i>1;--i)
		if(f[i]==f[i-1])
			break;
	int ansl=i;
	if(ansl==1&&ansr==2*n-1)
		return f[n]^(n&1)^1;
	if(f[ansl]==f[ansr])
		return f[ansl];
	if(n-ansl<ansr-n)
		return f[ansl];
	else
		return f[ansr];
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=2*n-1;++i)
		scanf("%d",&a[i]);
	l=1,r=2*n-1;
	while(l<r)
	{
		int mid=l+r>>1;
		if(check(mid))
			l=mid+1;
		else
			r=mid;
	}
	cout<<l;
}