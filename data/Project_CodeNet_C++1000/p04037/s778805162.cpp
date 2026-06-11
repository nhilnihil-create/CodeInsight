#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,ans;
int a[101010];
bool cmp(int u,int w)
{
	return u>w;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=n;++i)
		if (i+1>a[i+1]) 
		{
			for (int j=i+1;a[j]==i;++j)
				++ans;
			ans%=2;
			ans|=(a[i]-i)%2;
			break;
		}
	if (ans%2) printf("First\n");
	else printf("Second\n");
	return 0;
}