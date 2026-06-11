#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,x[N],t[N],m;
ll k,d[N];

typedef array<int,N> perm;
perm operator*(const perm &l,const perm &r)
{
	perm x;
	for(int i=1;i<=n;i++)x[i]=r[l[i]];
	return x;
}
perm power(perm a,ll x)
{
	perm ans;
	for(int i=1;i<=n;i++)ans[i]=i;
	for(;x;x>>=1,a=a*a)
		if(x&1)ans=ans*a;
	return ans;
}

int main()
{
	scanf("%d",&n);
	perm f;
	for(int i=1;i<=n;i++)scanf("%d",x+i),t[i]=x[i]-x[i-1],f[i]=i;
	scanf("%d%lld",&m,&k);
	for(int a;m--;)
	{
		scanf("%d",&a);
		swap(f[a],f[a+1]);
	}
	f=power(f,k);
	for(int i=1;i<=n;i++)d[i]=t[f[i]];
	for(int i=1;i<=n;i++)printf("%lld\n",d[i]+=d[i-1]);
}
