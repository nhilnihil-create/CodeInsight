#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#include<deque>
#include<set>
#define inf 1e9
#define eps 1e-6
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
ll a[3];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	for(register int i=0;i<3;i++)a[i]=read();
	sort(a,a+3);
	for(register int i=0;i<3;i++){if(a[i]%2==0){puts("0");return 0;}}
	printf("%lld\n",a[0]*a[1]);
	return 0;
}
