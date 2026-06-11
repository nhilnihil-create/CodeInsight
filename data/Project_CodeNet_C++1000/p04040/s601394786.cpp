#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL jc[300002];
LL quickmi(LL b,LL p,LL k)
{
	if(!p)return 1;
	LL ans=1,tmp=b;
	while(p)
	{
		if(p&1)ans=ans*tmp%k;
		tmp=tmp*tmp%k;
		p>>=1;
	}
	return ans%k;
}
LL C(LL n,LL m,LL k)
{
	if(n<m)return 0;
	return jc[n]*quickmi(jc[m]%k,k-2,k)%k*quickmi(jc[n-m]%k,k-2,k)%k;
}
LL Lucas(LL n,LL m,LL k)
{
	if(!m)return 1;
	return C(n%k,m%k,k)*Lucas(n/k,m/k,k)%k;
}
LL h,w,a,b,p;
LL ans;
int main()
{
	jc[0]=1;p=1e9+7;
	scanf("%lld%lld%lld%lld",&h,&w,&a,&b);
	if(h<w)
	{
		swap(h,w);
		swap(a,b);
	}
	for(LL i=1;i<=h+w;i++)jc[i]=jc[i-1]*i%p;
	if(Lucas(b-1,b-1,p)==0)
	{
		ans=(Lucas(w-b-1+h-1,w-b-1,p)+ans)%p;
	}
	for(int i=0;i<=h-a-1;i++)
	{
		ans=(ans+Lucas(b-1+i,b-1,p)*Lucas(w-b-1+h-1-i,w-b-1,p))%p;
	}
	printf("%lld\n",ans);
	return 0;
}
