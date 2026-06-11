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
#define N 200010
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
int n;
int a[N],tot,p[N];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(register int i=1;i<=n;i++)a[i]=p[i]=read();
	sort(p+1,p+n+1);tot=unique(p+1,p+n+1)-p-1;
	for(register int i=1;i<=n;i++){a[i]=lower_bound(p+1,p+tot+1,a[i])-p;}
	int ans=0;
	for(register int i=1;i<=n;i++)if(a[i]%2!=i%2)ans++;
	printf("%d\n",ans/2);
	return 0;
}
