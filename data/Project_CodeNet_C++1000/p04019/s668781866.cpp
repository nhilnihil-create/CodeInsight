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
#define N 2010
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
char s[N];
int n;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	int vis[4]={0,0,0,0};
	for(register int i=1;i<=n;i++)
	{
		if(s[i]=='N')vis[0]=1;
		if(s[i]=='S')vis[1]=1;
		if(s[i]=='W')vis[2]=1;
		if(s[i]=='E')vis[3]=1;
	}
	(((vis[0]&&vis[1])||((!vis[0])&&(!vis[1])))&&((vis[2]&&vis[3])||((!vis[2])&&(!vis[3]))))?puts("Yes"):puts("No");
	return 0;
}
