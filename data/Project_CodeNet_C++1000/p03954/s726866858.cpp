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
int n,a[200005],b[200005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n*2-1;++i)scanf("%d",a+i);
    int o=1;
    for(int k=17;k>=0;--k){
        int _=o+(1<<k);
        if(_>=n*2) continue;
        for(int i=1;i<=n*2-1;++i){
            if(a[i]<_)b[i]=0;
            else b[i]=1;
        }
        int l=n,r=n;
        while(l>1&&b[l-1]!=b[l])--l;
        while(r<n*2-1&&b[r+1]!=b[r])++r;
        if((min(n-l,r-n)^b[n])&1)o=_;
    }
    printf("%d\n",o);
    //system("pause");
    return 0;
}
