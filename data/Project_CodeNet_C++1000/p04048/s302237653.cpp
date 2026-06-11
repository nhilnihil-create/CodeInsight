//BadWaper gg
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<deque>
#include<bitset>
#include<map>
#include<set>
#define inf 1e9
#define eps 1e-6
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll read()
{
	char ch=getchar();
	ll s=0,w=1;
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
ll n,x;
ll a,b,ans;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),x=read();
	ans=n;
	a=x,b=n-x;
	while(true)
	{
		if(a<b)swap(a,b);
		ans+=((a/b)*2)*b;if(a%b==0){ans-=b;break;}
		a=a%b;
	}
	printf("%lld\n",ans);
	return 0;
}
