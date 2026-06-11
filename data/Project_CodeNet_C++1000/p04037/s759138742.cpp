#include<bits/stdc++.h>
#define MN 100005
int n,a[MN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	std::sort(a+1,a+1+n);
	for(int i=n,j=1;i;i--)
	{
		if(j+1>a[i-1])
		{
			int k=i;
			for(;a[k]>=j;k--);
			puts((((a[i]-j)&1)|((i-k-1)&1))?"First":"Second");
			break;
		}
		j++;
	}
}