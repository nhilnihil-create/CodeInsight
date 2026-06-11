#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int x[505];
int t[505];
int ans[252525];
int cnt[505];
int mk[252525];
bool cmp(const int &a,const int &b)
{
	return x[a]<x[b];
}
int n,nn;
bool jud()
{
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=nn;i++)
	{
		cnt[ans[i]]++;
		if(mk[i])
			if(mk[i]!=ans[i]||cnt[ans[i]]!=mk[i])
				return false;
	}
	return true;
}
int main()
{
	int now=1,nd;
	scanf("%d",&n);
	nn=n*n;
	memset(ans,0,sizeof(ans));
	memset(mk,0,sizeof(mk));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		ans[x[i]]=i;
		mk[x[i]]=i;
		t[i]=i;
	}
	sort(t+1,t+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		nd=t[i]-1;
		while(nd)
		{
			while(ans[now])
				now++;
			ans[now]=t[i];
			nd--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		nd=n-t[i];
		while(nd)
		{
			while(ans[now])
				now++;
			ans[now]=t[i];
			nd--;
		}
	}
	if(jud())
	{
		printf("Yes\n");
		for(int i=1;i<=nn;i++)
			printf("%d ",ans[i]);
	}
	else
		printf("No");
	return 0;
}