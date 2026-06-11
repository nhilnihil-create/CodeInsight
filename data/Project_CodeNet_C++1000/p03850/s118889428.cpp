#include<iostream>
#include<cstdio>
#include<cstdlib>
#define N 100010
#define ll long long
using namespace std;
ll f[3];
void read(ll &x)
{
	x=0;
	int ch=0,flag=1;
	for(;!isdigit(ch);ch=getchar())
	if(ch=='-') flag=-flag;
	for(;isdigit(ch);ch=getchar())
	x=x*10+ch-'0';
	x*=flag;
}
int main()
{
	int n;
	scanf("%d",&n);
	f[0]=0,f[1]=f[2]=-10000000000000ll;
	for(int i=1;i<=n;i++)
	{
		ll x;
		read(x);
		f[0]+=x;
		f[1]-=x;
		f[2]+=x;
		if(x<0)
		{
			f[2]=max(f[2],f[1]);
			f[1]=max(f[1],f[0]);
		}
		f[0]=max(f[0],f[1]);
		f[1]=max(f[1],f[2]);
	}
	printf("%lld\n",f[0]);
	return 0;
}
