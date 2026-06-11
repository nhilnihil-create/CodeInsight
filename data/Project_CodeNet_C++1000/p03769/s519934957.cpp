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
long long n;
deque<int> q;
int k,a[210];
int main()
{
	scanf("%lld",&n);
	while (n)
	{
		//cout<<n<<endl;
		if (n&1)
		{
			k++;
			a[k]=1;
			n=(n-1)>>1;
		}
		else
		{
			k++;
			a[k]=0;
			n--;
		}
	}
	for (int i=k;i;i--)
	{
		if (a[i])
		{
			q.push_back(k-i+1);
		} 
		else
		{
			q.push_front(k-i+1);
		}
	}
	printf("%d\n",k*2);
	while (!q.empty())
	{
		int x=q.front();
		q.pop_front();
		printf("%d ",x);
	}
	for (int i=1;i<=k;i++)
	{
		printf("%d ",i);
	}
    return 0;
}
//西窗外,钩月悬,云起落,慢拂面。