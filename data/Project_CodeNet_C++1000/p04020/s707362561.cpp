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
#define N 100010
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
ll a[N];ll ans;
ll n;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(register ll i=1;i<=n;i++)a[i]=read();
	for(register ll i=1;i<=n;i++)
	{
		ans+=a[i]/2;a[i]%=2;
		if(a[i]&&a[i+1]>=1)
		{
			ans++;a[i+1]--;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
