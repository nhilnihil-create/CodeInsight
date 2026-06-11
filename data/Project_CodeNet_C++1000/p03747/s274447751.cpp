#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int s[300010];
char op[300010];
int id[300010];
int n,m;
long long t;
bool cmp1(int a,int b)
{
	int pa,pb;
	if(op[a]=='2')
		pa=((s[a]-t)%m+m)%m;
	else pa=(s[a]+t)%m;
	if(op[b]=='2')
		pb=((s[b]-t)%m+m)%m;
	else pb=(s[b]+t)%m;
	if(pa!=pb)return pa<pb;
	return op[a]=='2';
}
int id2[300010];
bool cmp2(int a,int b)
{
	if(s[a]!=s[b])
		return s[a]<s[b];
	return op[a]=='2';
}
int ans[300010];
int main()
{
	cin>>n>>m>>t;
	for(int i=0;i<n;i++)
	{
		cin>>s[i]>>op[i];
		s[i]--;id[i]=id2[i]=i;
	}
	sort(id,id+n,cmp1);
	sort(id2,id2+n,cmp2);
	int pos=0;
	if(op[0]=='2')
	{
		long long x=s[0]-t;
		for(int i=0;i<n;i++)
			if(op[i]=='1')
			{
				long long y=s[i]+t;
				if(s[i]>s[0])y-=m;
				if(y<x)continue;
				pos=(pos+(y-x)/m+1)%n;
			}
		pos=(n-pos)%n;
	}
	else{
		long long x=s[0]+t;
		for(int i=0;i<n;i++)
			if(op[i]=='2')
			{
				long long y=s[i]-t;
				if(s[i]<s[0])y+=m;
				if(y>x)continue;
				pos=(pos+(x-y)/m+1)%n;
			}
	}
	int p=0;
	for(int i=0;i<n;i++)
		if(id2[i]==0)p=i;
	p=(p+pos)%n;
	int q=0;
	for(int i=0;i<n;i++)
		if(id[i]==0)q=i;
	for(int i=0;i<n;i++)
	{
		int j=id[(q+i)%n];
		int x=(q+i)%n,y;
		if(op[j]=='2')
			y=((s[j]-t)%m+m)%m;
		else y=(s[j]+t)%m;
		int z=id2[(p+i)%n];
		ans[z]=y+1;
	}
	for(int i=0;i<n;i++)
	{
		if(ans[i]==m)
		{
			ans[i]=0;
		}
	}
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}