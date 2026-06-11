#include<bits/stdc++.h>
using namespace std;
long long aa;bool bb;char ch;
long long scan()
{
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	ch=='-'?(bb=1,aa=0):(bb=0,aa=ch-48);
	while(ch=getchar(),(ch>='0'&&ch<='9'))
		aa=aa*10+ch-48;
	return (bb?(-aa):(aa));
}
struct cmp1
{
	bool operator()(long long a,long long b){
		return a>b;
	}
};
priority_queue<long long,vector<long long>,cmp1> h1;
struct cmp2
{
	bool operator()(long long a,long long b){
		return a<b;
	}
};
priority_queue<long long,vector<long long>,cmp2> h2;
long long ans,a[300010],sum1[300010],sum2[300010];
int n;
long long Max(long long u,long long v){return u>v?u:v;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=3*n;++i)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;++i)
	{
		h1.push(a[i]);
		sum1[i]=sum1[i-1]+a[i];
	}
	for(int i=n+1;i<=n*2;++i)
	{
		h1.push(a[i]);
		sum1[i]=sum1[i-1]+a[i];
		sum1[i]-=h1.top();
		h1.pop();
	}
	for(int i=n*3;i>n*2;--i)
	{
		h2.push(a[i]);
		sum2[i]=sum2[i+1]+a[i];
	}
	for(int i=n*2;i;--i)
	{
		h2.push(a[i]);
		sum2[i]=sum2[i+1]+a[i];
		sum2[i]-=h2.top();
		h2.pop();
	}
	ans=sum1[n]-sum2[n+1];
	for(int i=n+1;i<=n*2;++i)
		ans=Max(ans,sum1[i]-sum2[i+1]);
	cout<<ans<<endl;
}