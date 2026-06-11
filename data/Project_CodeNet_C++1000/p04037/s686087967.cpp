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
int n,a[100010],cnt;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	int k=1;
	while (k<=n && k<=a[k])
	{
		k++;
	}
	k--;
	int p;
	if ((a[k]-k)&1)
	{
		p=1;
	}
	else
	{
		p=0;
		int j=k+1;
		while (j<=n && a[j]==k)
		{
			j++;
			p^=1;
		}
	}
	if (p)
	{
		puts("First");
	}
	else
	{
		puts("Second");
	}
    return 0;
}
//因为有了因为，所以有了所以。既然已成既然，何必再说何必。