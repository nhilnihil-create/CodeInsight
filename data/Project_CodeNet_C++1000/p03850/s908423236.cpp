#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<ctype.h>
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
#include<math.h>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<stdio.h>
#include<stdlib.h>
#include<streambuf>
#include<string.h>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
using namespace std;
typedef long long LL;
inline void gtmx(LL &a,LL b){
	if (a<b) a=b;
}
inline void gtmn(LL &a,LL b){
	if (a>b) a=b;
}
int a[100010];
int op[100010];
LL dp[100010][4];
int main(void){
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;++i){
		scanf("%d",&a[i]);
		char c=getchar();
		while(c!='+'&&c!='-') c=getchar();
		op[i]=(c=='+')?1:-1;
	}
	scanf("%d",&a[n]);
	memset(dp,155,sizeof(dp));
	dp[1][0]=a[1];
	for (int i=1;i<n;++i){
		gtmx(dp[i+1][0],dp[i][0]+a[i+1]*op[i]);
		gtmx(dp[i+1][0],dp[i][1]+a[i+1]*op[i]);
		gtmx(dp[i+1][1],dp[i][1]-a[i+1]*op[i]);
		gtmx(dp[i+1][2],dp[i][2]+a[i+1]*op[i]);
		if (op[i]==-1){
			gtmx(dp[i+1][1],dp[i][0]+a[i+1]*op[i]);
			gtmx(dp[i+1][2],dp[i][1]+a[i+1]);
		}
		gtmx(dp[i+1][1],dp[i+1][2]);
		gtmx(dp[i+1][0],dp[i+1][1]);
	}
	printf("%lld",dp[n][0]);
}