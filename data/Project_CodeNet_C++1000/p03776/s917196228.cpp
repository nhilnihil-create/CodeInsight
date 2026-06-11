#include<cstdio>
#include<iostream>
#include<algorithm>
#define maxn 55
#define ll long long

using namespace std;

ll n,l,r,js1=0,js2=0,ans1,ans2=0;

ll a[maxn],s[maxn][maxn];

bool cmp(ll a,ll b)
{
	return a>b;
}

int main()
{
	s[0][0]=1;
	for(int i=1;i<=50;i++)
	{
		s[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			s[i][j]=s[i-1][j]+s[i-1][j-1];
		}
	}
	cin>>n>>l>>r;
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=l;i++)
	{
		ans2+=a[i];
	}
	for(ll i=1;i<=n;i++)
	{
		if(a[i]==a[l])
		{
			js1++;
		}
	}
	for(ll i=1;i<=l;i++)
	{
		if(a[i]==a[l])
		{
			js2++;
		}
	}
	if(a[1]==a[l])
	{
		for(ll i=l;i<=r;i++)
		{
			ans1+=s[js1][i];
		}
	}
	else
	{
		ans1=s[js1][js2];
	}
	printf("%lf\n%lld",(double)ans2/l*1.0,ans1);
	return 0;
}