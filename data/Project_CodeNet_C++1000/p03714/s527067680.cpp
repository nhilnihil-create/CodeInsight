
#include<bits/stdc++.h>
#define LL long long
#define MOD (LL)1000000007
#define pi acos(-1.0)
#define ULL unsigned long long
#define mem_1(str) memset(str,-1,sizeof(str))
#define mem0(str) memset(str,0,sizeof(str))
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define INF 999999999
using namespace std;
LL num[500000]; 
LL f[500000],e[500000];
priority_queue<LL> qt;
priority_queue<LL , vector<LL> , greater<LL> > qtt;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=3*n;i++)
	{
		scanf("%lld",&num[i]);
	}
	LL sum=0;
	for(int i=1;i<=3*n;i++)
	{
		qtt.push(num[i]);
		sum+=num[i];
		if(qtt.size()>n)
		{
			sum-=qtt.top();
			qtt.pop();
		}
		f[i]=sum;
	}
	sum=0;
	for(int i=3*n;i>0;i--)
	{
		qt.push(num[i]);
		sum+=num[i];
		if(qt.size()>n)
		{
			sum-=qt.top();
			qt.pop();
		}
		e[i]=sum;
	}
	LL ans=(LL)-1e18;
	for(int i=n;i<=2*n;i++)
	{
		ans=max(ans,f[i]-e[i+1]);
	 } 
	 printf("%lld",ans);
}