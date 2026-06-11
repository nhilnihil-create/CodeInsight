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
struct node
{
	int l,r,d;
}a[300010];
int n,m,bit[100010];
bool cmp(node x,node y)
{
	return x.d<y.d;
}
inline int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int v)
{
	for (;x<=m;x+=lowbit(x))
	{
		bit[x]+=v; 
	}
}
int ask(int x)
{
	int res=0;
	for (;x;x-=lowbit(x))
	{
		res+=bit[x];
	}
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].l,&a[i].r);
		a[i].d=a[i].r-a[i].l+1;
	}
	sort(a,a+n,cmp);
	int k=0;
	for (int i=1;i<=m;i++)
	{
		while (k<n && a[k].d<i)
		{
			add(a[k].l,1);
			add(a[k].r+1,-1);
			k++;
		}
		int res=n-k;
		for (int j=i;j<=m;j+=i)
		{
			res+=ask(j);
		}
		printf("%d\n",res);
	}
    return 0;
}
//客舍并州已十霜，归心日夜忆咸阳。
//无端更渡桑乾水，却望并州是故乡。
//——刘皂《旅次朔方》