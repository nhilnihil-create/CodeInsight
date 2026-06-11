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
int n,a[105],m;
bool ok=1;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int x;
        scanf("%d",&x);
        m=max(m,x);
        ++a[x];
    }
    if(m&1){
        for(int i=1;i<=m/2;++i)if(a[i])ok=0;
        if(a[m/2+1]!=2)ok=0;
        for(int i=m/2+2;i<=m;++i)if(a[i]<2)ok=0;
    }
    else{
        for(int i=1;i<m/2;++i)if(a[i])ok=0;
        if(a[m/2]!=1)ok=0;
        for(int i=m/2+1;i<=m;++i)if(a[i]<2)ok=0;
    }
    if(ok)puts("Possible");
    else puts("Impossible");
    //system("pause");
    return 0;
}
