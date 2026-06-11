#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MOD(x) ((x)%mod)
int n,m;
long long a[300005];
long long b[300005];
long long c[300005];
long long sum1,sum2;
long long ans;
priority_queue<long long , vector<long long> , greater<int> >q1;
priority_queue<long long , vector<long long> , less<int> >q2;
int main()
{
	scanf("%d",&n);
	m=3*n;
	for(int i=1;i<=m;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
	{
		if(q1.size()<n)
		{
			q1.push(a[i]);
			b[i]=b[i-1]+a[i];
		}
		else
		{
			if(a[i]>q1.top())
			{
				b[i]=b[i-1]-q1.top()+a[i];
				q1.pop();
				q1.push(a[i]);
			}
			else b[i]=b[i-1];			
		}
	}
	for(int i=m;i>=1;i--)
	{
		if(q2.size()<n)
		{
			q2.push(a[i]);
			c[i]=c[i+1]+a[i];
		}
		else
		{
			if(a[i]<q2.top())
			{
				c[i]=c[i+1]-q2.top()+a[i];
				q2.pop();
				q2.push(a[i]);
			}
			else c[i]=c[i+1];
		}
	}
	bool sign=0;
	for(int i=n;i<=2*n;i++)
	{
		if(sign==0)
		{
			ans=b[i]-c[i+1];
			sign=1;
		}
		else ans=max(ans,b[i]-c[i+1]);
	}
	printf("%lld",ans);
	return 0;
}