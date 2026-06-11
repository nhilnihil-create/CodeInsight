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
#define N 110
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
int a[N],num[N];
inline void L(){printf("Impossible\n");exit(0);}
inline void W(){printf("Possible\n");exit(0);}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(register int i=1;i<=n;i++)num[read()]++;
	for(register int i=1;i<=n;i++)
	{
		if(num[i])
		{
			if(num[i]>2){L();}
			int x;
			if(num[i]==1)x=2*i;
			else x=2*i-1;
			for(register int j=i+1;j<=x;j++){if(num[j]<2)L();}
			for(register int j=x+1;j<=n;j++){if(num[j])L();}
			W();
		}
	}
	return 0;
}
