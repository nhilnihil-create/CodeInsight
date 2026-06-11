#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;
int n,i,j,a[100005],cnt[100005];
int main()
{
	cin>>n;int mx=0,mi=n+1;
	rep(i,n){cin>>a[i];mx=max(mx,a[i]);mi=min(mi,a[i]);cnt[a[i]]++;}
	if(mx-mi>1){puts("No");return 0;}
	if(mx==mi)
	{
		if(mi==n-1||mi*2<=n)
		{
			puts("Yes");
		}
		else
		{
			puts("No");
		}
	}
	else
	{
		if(cnt[mi]>mi)
		{
			puts("No");
		}
		else if(n-cnt[mi]<2*(mx-cnt[mi]))
		{
			puts("No");
		}
		else puts("Yes");
	}
	return 0;
}