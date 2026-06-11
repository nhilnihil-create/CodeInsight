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
int n,m,to[100010],st[100010];
long long a[100010],b[100010],k;
bool used[100010];
int main()
{
	scanf("%d",&n);
	long long lst=0;
	for (int i=1;i<=n;i++)
	{
		long long x;
		scanf("%lld",&x);
		a[i]=x-lst;
		lst=x;
		to[i]=i;
	}
	scanf("%d%lld",&m,&k);
	for (int i=0;i<m;i++)
	{
		int x;
		scanf("%d",&x);
		swap(to[x],to[x+1]);
	}
	for (int i=1;i<=n;i++)
	{
		if (used[i])
		{
			continue;
		}
		int cnt=0,now=i;
		while (!used[now])
		{
			used[now]=true;
			st[cnt]=now;
			cnt++;
			now=to[now];
		}
		long long q=k%cnt;
		for (int j=0;j<cnt;j++)
		{
			to[st[j]]=st[(j-q+cnt)%cnt];
		}
	}
	for (int i=1;i<=n;i++)
	{
		b[to[i]]=a[i];
	}
	long long now=0;
	for (int i=1;i<=n;i++)
	{
		now+=b[i];
		printf("%lld.0\n",now);
	}
    return 0;
}
//月上柳梢头，人约黄昏后。
//——欧阳修《生查子·元夕》