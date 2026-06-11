#include <bits/stdc++.h>
using namespace std;

typedef long long  LL;
LL n,m,k,x[100010],a[100010],_[100010];

void mul(LL *a,LL *b)
{
	for (int i=1; i<=n; i++)  _[i]=a[b[i]];
	for (int i=1; i<=n; i++)  a[i]=_[i];
}

void work()
{
	scanf("%lld",&n);
	for (int i=1; i<=n; i++)  scanf("%lld",&x[i]),a[i]=i;
	for (int i=n; i; i--)  x[i]-=x[i-1];
	scanf("%lld %lld",&m,&k);
	for (int i=1,x; i<=m; i++)  scanf("%d",&x),swap(a[x],a[x+1]);
	while (k)
		{
			if (k&1)  mul(x,a);
			mul(a,a),k>>=1;
		}
	for (int i=1; i<=n; i++)  x[i]+=x[i-1],printf("%lld\n",x[i]);
}

int main()
{
	work();
	return 0;
}
