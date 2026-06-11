#include<bits/stdc++.h>
using namespace std;
int n,mk,num[100005],cc,bs[100005],col[100005];
bool pp=true,bi[100005];
long long ss;
vector<int>pos;
bool ch(int mm)
{
	int r=mm,rr=0;
	memset(bs,0,sizeof(bs));
	memset(col,0,sizeof(col));
	bool p=true;
	if(pos.size()!=0)
	{
		int aa=pos.size();
		if(r-aa<=0)return false;
		for(int i=1;i<=n;i++)
		{
			if(bi[i])continue;
			else
			{
				bs[rr+aa]++;
				col[i]=rr+aa;
				rr++;
				rr%=(r-aa);	
			}
		}
		for(int i=0;i<aa;i++)
		{
			bs[i]++;
			col[pos[i]]=i;
		}
		for(int i=1;i<=n;i++)
		{
			if(bs[col[i]]==1)
			{
				if(num[i]!=r-1)p=false;
			}
			else
			{
				if(num[i]!=r)p=false;	
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			bs[rr]++;
			col[i]=rr;
			rr++;
			rr%=(r);
		}
		for(int i=1;i<=n;i++)
		{
			if(bs[col[i]]==1)
			{
				if(num[i]!=r-1)p=false;
			}
			else
			{
				if(num[i]!=r)p=false;	
			}
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		printf("%d ",col[i]);
	}*/
	return p;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&num[i]);
    	mk=max(num[i],mk);
    	ss+=num[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(num[i]<mk)cc++,pos.push_back(i),bi[i]=true;
		if(num[i]<mk-1)pp=false;
	}
	if(ch(mk))
	{
		printf("Yes");
	}
	else
	{
		if(ch(mk+1))
		{
			printf("Yes");
		}
		else
		{
			printf("No");
		}
	}
}