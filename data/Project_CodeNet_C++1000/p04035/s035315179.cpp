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
int n,L;
int a[N];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),L=read();
	for(register int i=1;i<=n;i++)a[i]=read();
	int pos=0;
	for(register int i=1;i<n;i++)
	{
		if(a[i]+a[i+1]>=L){pos=i;break;}
	}
	if(!pos){printf("Impossible\n");return 0;}
	printf("Possible\n");
	for(register int i=1;i<pos;i++)printf("%d\n",i);
	for(register int i=n-1
	;i>pos;i--)printf("%d\n",i);
	printf("%d\n",pos);
	return 0;
}
