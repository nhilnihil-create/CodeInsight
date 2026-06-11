#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2e5+500;
char st[10];
int w[N],fh[N],n,lst[N];long long s[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",w+i);
		if(i!=n)
		{
			scanf("%s",st+1);
			if(st[1]=='-')fh[i]=-1;else fh[i]=1;
		}
	}
	long long ans=w[1];for(int i=2;i<=n;i++)ans+=fh[i-1]*w[i];
	for(int i=1;i<=n;i++)s[i]=s[i-1]+w[i];
	lst[n]=n;long long pres=0;
	for(int i=n-1;i>=1;i--)if(fh[i]==1)lst[i]=lst[i+1];else lst[i]=i;
	fh[0]=1;
	for(int i=1;i<n;i++)
	{
		pres+=fh[i-1]*w[i];
		if(fh[i]==-1)ans=max(ans,s[n]-s[lst[i+1]]-(s[lst[i+1]]-s[i])+pres);
	}
	cout<<ans<<endl;
}