#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<complex>
#include<string>
#include<cstring>
using namespace std;
#define rep2(x,from,to) for(long long x=(from);(x)<(to);(x)++)
#define rep(x,to) rep2(x,0,to)
#define INF 100000000
#define debug(x) cout<<#x<<": "<<x<<endl

#define all(x) x.begin(),x.end()
typedef pair<long long,long long> P;
typedef pair<long long,P> PP;
long long n;
long long k;
long long kl[35];
long long t;
long long kn;
long long kk;
long long an[100005];
long long a[100005][32];
long long b[100005];
long long ansa;
long long ansb;
long long ans;
long long A;
long long ff;
long long limi;
int main()
{
	cin>>n;
	cin>>k;
	kk=k;
	for(long long i=0;1;i++)
	{
		kl[i]=kk&1;
		
		kk=kk>>1;
		if(kk==0)
		{
			kn=i+1;
			break;
		}
	}
	rep(i,n)
	{
		cin>>t>>b[i];
		for(long long j=0;1;j++)
		{
			a[i][j]=t&1;
			t=t>>1;
			if(t==0)
			{
				an[i]=j+1;
				break;
			}
		}
	}
	rep(i,n)
	{
		if(an[i]<kn)
		{
			ansa+=b[i];
		}
	}
	long long f;
	rep(i,n)
	{
		f=1;
		rep(j,max(an[i],kn))
		{
			if(kl[j]<a[i][j])f=0;
		}
		ansb+=(f*b[i]);
	}
	/*rep(i,n)
	{
		rep(j,kn)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}*/
	for(long long i=0;i<n;i++)
	{
		if(kn<an[i])b[i]=0;
	}
	for(long long keta=1;keta<kn;keta++)
	{
		ans=0;
		//f=1;
		rep(i,n)
		{
			f=1;
			for(long long j=keta;j<kn;j++)
			{
				if(kl[j]<a[i][j])f=0;
			}
			ff=0;
			for(long long j=keta-1;j>=0;j--)
			{
				if(kl[j]==1)
				{
					limi=j;
					break;
				}
				if(j==0)
				{
					ff=1;
				}
			}
			if(ff==1)
			{
				rep(j,keta)
				{
					if(a[i][j]==1)f=0;
				}
				if(f==1)
				{
					ans+=b[i];
				}
			}
			else
			{
				rep2(j,limi,keta)
				{
					if(a[i][j]==1)f=0;
				}
				if(f==1)
				{
					ans+=b[i];
				}
			}
		}
		//cout<<ans<<endl;
		A=max(ans,A);
	}
	cout<<max(A,max(ansa,ansb))<<endl;
	return  0;
}