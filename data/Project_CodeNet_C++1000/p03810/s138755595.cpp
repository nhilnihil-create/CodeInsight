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
int n,a[100010];
int gcd(int x,int y)
{
	if (!y)
	{
		return x;
	}
	else
	{
		return gcd(y,x%y);
	}
}
bool nim()
{
	long long s=0;
	bool f=false;
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		s+=a[i]-1;
		if (a[i]==1)
		{
			f=true;
		}
		if (a[i]&1)
		{
			cnt++;
		}
	}
	if (f)
	{
		return s%2;
	}
	if ((n-cnt)%2)
	{
		return true;
	}
	if (cnt==1)
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i]&1)
			{
				a[i]--;
				break;
			}
		}
		int g=a[1];
		for (int i=2;i<=n;i++)
		{
			g=gcd(g,a[i]);
		}
		for (int i=1;i<=n;i++)
		{
			a[i]/=g;
		}
		return !(nim());
	}
	return false;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	if (nim())
	{
		puts("First");
	}
	else
	{
		puts("Second");
	}
    return 0;
}