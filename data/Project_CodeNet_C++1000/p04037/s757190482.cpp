#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
bool cmp(const int &x,const int &y)
{
	return x>y;
}
int a[101010];
int main()
{
	int n,now=1,cnt,k;
	int ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[n+1]=0;
	sort(a+1,a+1+n,cmp);
	while(a[now+1]>=now+1)
		now++;
	ans|=((a[now]-now)&1);
	k=now;
	while(a[now+1]>=k)
	{
		cnt++;
		now++;
	}
	ans|=(cnt&1);
	if(ans)
		printf("First");
	else
		printf("Second");
	return 0;
}