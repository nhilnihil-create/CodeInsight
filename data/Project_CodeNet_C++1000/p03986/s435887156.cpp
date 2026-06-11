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
int v,sum;
char s[N];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(register int i=1;i<=len;i++)
	{
		if(s[i]=='S')v++;
		if(s[i]=='T'){if(v)v--;else sum++;}
	}
	cout<<sum+v<<endl;
	return 0;
}
