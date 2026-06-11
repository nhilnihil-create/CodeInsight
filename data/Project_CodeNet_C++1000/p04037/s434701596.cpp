#include<bits/stdc++.h>
#define MN 100005
int n,a[MN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	std::sort(a+1,a+1+n);
	for(int i=n,j=1;i>=1;i--,j++)
		if(j+1>a[i-1]) {
			bool ans=0,now=0;
			for(int k=i-1;k;k--)
			{
				if(a[k]!=j) break;
				now^=1;
			}
			ans|=(a[i]-j)&1;
			ans|=now;
			puts(ans?"First":"Second");
			return 0;
		}
}