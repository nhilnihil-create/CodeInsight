#include<bits/stdc++.h>
#define LL long long
#define maxn 100005
using namespace std;
int a[maxn];
void solve(int n)
{
	int mx=0,mn=n;
	for(int i=1;i<=n;i++)
	{
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	if(mx-mn>=2)
	{
		puts("No");
		return ;
	}
	if(mx==mn)
	{
		if(mx==n-1) puts("Yes");
		else if(mx*2<=n) puts("Yes");
		else puts("No");
		return ;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(a[i]==mn) cnt++;
	if(cnt<mx&&2*(mx-cnt)+cnt<=n)
	{
		puts("Yes");
		return ;
	}
	puts("No");
	return ;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	solve(n);
}