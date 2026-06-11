#include<bits/stdc++.h>
#define ll long long
#define N 2010
using namespace std;
int n;
int q[N<<1],head,tail,p[N<<1];
ll res,ans,a[N],x;
int main()
{
	scanf("%d%lld",&n,&x);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=0;i<n;i++)
	{
		if(i>0&&x*i>=ans)break;
		head=1;
		tail=0;
		res=0;
		for(int j=n-i+1;j<=n;j++)
		{
			while(head<=tail&&q[tail]>=a[j])--tail;
			q[++tail]=a[j];p[tail]=j-n;
		}
		for(int j=1;j<=n;j++)
		{
			while(head<=tail&&q[tail]>=a[j])--tail;
			q[++tail]=a[j];p[tail]=j;
			while(p[head]<j-i)++head;
			res+=q[head];
		}
		if(i==0)ans=res;
		else ans=min(ans,res+x*i);
	}
	printf("%lld",ans);
}