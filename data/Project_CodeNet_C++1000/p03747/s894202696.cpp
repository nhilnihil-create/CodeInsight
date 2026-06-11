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
int n,l,t,a[100010];
long long cnt;
int main()
{
	scanf("%d%d%d",&n,&l,&t);
	for (int i=0;i<n;i++)
	{
		int x,w;
		scanf("%d%d",&x,&w);
		if (w==1)
		{
			x+=t;
		}
		else
		{
			x-=t;
		}
		cnt+=x/l;
		x%=l;
		if (x<0)
		{
			cnt--;
			x+=l;
		}
		a[i]=x;
	}
	cnt=(cnt%n+n)%n;
	sort(a,a+n);
	for (int i=0;i<n;i++)
	{
		printf("%d\n",a[(cnt+i)%n]);
	}
    return 0;
}
//石壕村里夫妻别，泪比长生殿上多。
//——袁枚《马嵬》