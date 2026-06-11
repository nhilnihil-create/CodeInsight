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
#define orz  1000000007
using namespace std;
int n,a[100005],ans,cnt[2];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    while(1){
        cnt[0]=cnt[1]=0;
        for(int i=1;i<=n;++i)if(a[i]>1)++cnt[a[i]&1];
        if(cnt[0]&1){
            ans^=1;
            break;
        }
        if(cnt[1]!=1||cnt[0]!=n-1) break;
        for(int i=1;i<=n;++i)if(a[i]>1&&(a[i]&1))--a[i];
        int o=a[1];
        for(int i=2;i<=n;++i)o=__gcd(o,a[i]);
        for(int i=1;i<=n;++i)a[i]/=o;
        ans^=1;
    }
    if(ans)puts("First");
    else puts("Second");
    //system("pause");
    return 0;
}
