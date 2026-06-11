#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
int p[100010];
int main()
{
	int ans=0,n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	int len=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]==i) len++;
		else ans+=(len+1)/2,len=0;
	}
	ans+=(len+1)/2;
	printf("%d",ans);
}