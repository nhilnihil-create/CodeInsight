#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;
char s[200005];
int dp[200005],pre[200005][28];
int main(){
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<=25;++i)	pre[len][i]=len;
	dp[len]=1;
	for(int i=len-1;~i;--i)
	{
		for(int j=0;j<=25;++j)	pre[i][j]=pre[i+1][j];
		pre[i][s[i]-'a']=i;
		dp[i]=len+1;
		for(int j=0;j<=25;++j)	dp[i]=min(dp[i],dp[pre[i][j]+1]+1);
	}
	int ans=dp[0],Last=0;
	for(int i=1;i<=ans;++i)
	{
		for(int j=0;j<=25;++j)
		{
			if(dp[pre[Last][j]+1]+1==dp[Last])
			{
				putchar('a'+j);
				Last=pre[Last][j]+1;
				break;
			}
		}
	}
	putchar('\n');
	return 0;
}