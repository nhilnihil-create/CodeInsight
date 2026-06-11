#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<cmath>
#include<functional>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void sort(int &a,int &b)
{
	if(a>b)
		swap(a,b);
}
void open(const char *s)
{
#ifndef ONLINE_JUDGE
	char str[100];
	sprintf(str,"%s.in",s);
	freopen(str,"r",stdin);
	sprintf(str,"%s.out",s);
	freopen(str,"w",stdout);
#endif
}
int rd()
{
	int s=0,c;
	while((c=getchar())<'0'||c>'9');
	do
	{
		s=s*10+c-'0';
	}
	while((c=getchar())>='0'&&c<='9');
	return s;
}
int upmin(int &a,int b)
{
	if(b<a)
	{
		a=b;
		return 1;
	}
	return 0;
}
int upmax(int &a,int b)
{
	if(b>a)
	{
		a=b;
		return 1;
	}
	return 0;
}
ll p=1000000007;
ll f[1000010];
ll s[1000010];
int main()
{
	int n;
	scanf("%d",&n);
	f[0]=1;
	f[1]=n;
	s[0]=1;
	s[1]=n+1;
	int i;
	for(i=2;i<=n;i++)
	{
		f[i]=f[i-1];
		f[i]=(f[i]+ll(n-1)*(n-1))%p;
		if(i<=2)
			f[i]=(f[i]+n-1)%p;
		else
			f[i]=(f[i]+s[i-3]+n-i+1)%p;
		s[i]=(s[i-1]+f[i])%p;
	}
	printf("%lld\n",f[n]);
	return 0;
}