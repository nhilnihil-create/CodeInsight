#include <bits/stdc++.h>

using namespace std;
int n,d,dat[100005],mx,res,cnt;
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++) scanf("%d",&dat[i]);
	mx=dat[n];
	for(int i=n-1;i>=1;i--)
	{
		if(mx>dat[i])
		{
			if(mx-dat[i]>res) res=mx-dat[i],cnt=1;
			else if(mx-dat[i]==res) cnt++;
		}
		mx=max(mx,dat[i]);
	}
	printf("%d",cnt);
	return 0;
}