#include<bits/stdc++.h>
using namespace std;

priority_queue<long long>x; 
priority_queue<long long ,vector<long long>,greater<long long> >y;
long long l[300001],r[300001],s[300001]; 
int main()
{
	int n,m,t;	
	long long ans=-100000000000000,p,q;	
	scanf("%d",&n);
	for(int i=1;i<=3*n;i++)
	{
	    scanf("%lld",&s[i]);
	}
	p=0;
	q=0;
	for(int i=1;i<=3*n;i++)
	{
		y.push(s[i]);
		p+=s[i];
		l[i]=p;
		x.push(s[3*n-i+1]);
		q+=s[3*n-i+1];
		r[3*n-i+1]=q;
		if(y.size()>n)
		{
			p-=y.top();
			l[i]=p;
			y.pop();
		}
		if(x.size()>n)
		{
			q-=x.top();
			r[3*n-i+1]=q;
			x.pop();
		}
	}
	for(int i=n;i<=2*n;i++)
	{
		if (l[i]-r[i+1]>ans) 
		  ans=l[i]-r[i + 1];
	}
	printf("%lld",ans);
	return 0;
}