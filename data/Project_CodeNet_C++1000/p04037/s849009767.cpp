#include<bits/stdc++.h>
using namespace std;
int n,a[100005],pos,pos2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(a[i+1]<=i||i==n)
		{
			pos=i-1;
			break;
		}
	}
	pos2=n;
	for(int i=pos+1;i<=n;i++)
	{
		if(a[i]<=pos)
		{
			pos2=i-1;
			break;
		}
	}
	if(((a[pos+1]-pos)&1)&&((pos2-pos)&1)) puts("Second");
	else puts("First");
	return 0;
}