#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int n,a[100010],b[100010],du[100010];
int cnt,head[100010],to[200010],nxt[200010];
void add(int x,int y)
{
	cnt++;
	to[cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
void dfs(int x,int fa)
{
	if (du[x]==1)
	{
		b[x]=a[x];
		return;
	}
	b[x]=2*a[x];
	for (int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if (y==fa)
		{
			continue;
		}
		dfs(y,x);
		b[x]-=b[y];
	}
	if (b[x]>a[x])
	{
		puts("NO");
		exit(0);
	}
}
void work(int x,int fa)
{
	if (du[x]==1)
	{
		return;
	}
	int cnt=0;
	for (int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if (y==fa)
		{
			continue;
		}
		work(y,x);
		if (b[x]+b[y]>a[x])
		{
			cnt+=b[x]+b[y]-a[x];
		}
	}
	if (cnt>b[x])
	{
		puts("NO");
		exit(0);
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
		du[x]++;
		du[y]++;
	}
	if (n==2)
	{
		if (a[1]==a[2])
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
		return 0;
	}
	int rt=1;
	for (int i=1;i<=n;i++)
	{
		if (du[i]>1)
		{
			rt=i;
			break;
		}
	}
	dfs(rt,0);
	if (b[rt])
	{
		puts("NO");
		return 0;
	}
	work(rt,0);
	puts("YES");
    return 0;
}
//忽晴忽雨的江湖,祝你有梦为马,永远随处可栖。
//——大冰《他们最幸福》