#include<iostream>
#include<algorithm>
#include<cmath>
#include<string.h>
#include<cstdio>
#include<map>
using namespace std;
typedef long long ll;
const int MAX=200000+10; 
int n,k;
ll a[MAX];
ll b[MAX];
ll s[MAX];
map<ll, int>mp;
int lowbit(int x)
{
	return (x&-x);
}
ll sum(int x)
{
	ll ans=0;
	while(x>0)
	{
		ans+=a[x];
		x-=lowbit(x);
	}
	return ans;
}
void inite(int x,int num)//维护前缀数组a 
{
    while(x<=n+1){
        a[x]+=(long long)num;
        x+=lowbit(x);
    }
}
int main()
{
	scanf("%d%d",&n,&k);
	s[0]=b[0]=0;
	for(int i=1;i<=n;i++)
	{	
		int t;
		scanf("%d",&t);
		s[i]=s[i-1]+(long long)(t-k);
		b[i]=s[i];
	}
	sort(b,b+1+n);
	int tot=0;
	for(int i=0;i<=n;i++)
		if(!mp.count(b[i]))mp[b[i]]=++tot;
	memset(a,0,sizeof(a));
	ll res=0;
	for(int i=0;i<=n;i++)
	{
		res+=sum(mp[s[i]]);
		inite(mp[s[i]],1);
	}
	printf("%lld\n",res); 
return 0;
}