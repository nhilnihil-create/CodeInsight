//Relive your past life.
//Face your demons.
//The past is never dead,it is not even past.
//The memories are not only the key to the past but...also to the future.
//coded in Rusty Lake
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
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007ll
using namespace std;
int n,k;
ll jc[4000005],njc[4000005],dp[2005][2005];
ll fp(ll x,int k=1000000005){
    ll ans=1;
    while(k){
        if(k&1)ans=ans*x%orz;
        k>>=1,x=x*x%orz;
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&k);
    if(n==1||k==1){
        puts("1");
        return 0;
    }
    jc[0]=1;
    for(int i=1;i<=n*k;++i)jc[i]=jc[i-1]*i%orz;
    njc[n*k]=fp(jc[n*k]);
    for(int i=n*k;i;--i)njc[i-1]=njc[i]*i%orz;
    dp[0][1]=1;
    for(int i=2;i<=n;++i)dp[0][i]=dp[0][i-1]*jc[i*k-i-1]%orz*njc[k-2]%orz*njc[i*k-i-k+1]%orz;
    for(int i=1;i<n;++i){
        dp[i][i]=dp[i-1][i];
        for(int j=i+1;j<=n;++j)dp[i][j]=(dp[i][j-1]*jc[i+j*k-j-1]%orz*njc[k-2]%orz*njc[i+j*k-j-k+1]%orz+dp[i-1][j])%orz;
    }
    printf("%lld\n",dp[n-1][n]*jc[n]%orz);
    //system("pause");
    return 0;
}
