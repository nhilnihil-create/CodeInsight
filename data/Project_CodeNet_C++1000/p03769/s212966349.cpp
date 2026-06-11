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
ll n;
int k,o;
deque<int> q;
int main(){
    scanf("%lld",&n);
    ++n;
    for(int i=50;i>=0;--i){
        if(n&(1ll<<i)){
            k=i;
            break;
        }
    }
    for(int i=k-1;i>=0;--i){
        q.push_back(++o);
        if(n&(1ll<<i))q.push_front(++o);
    }
    printf("%d\n",o*2);
    for(int i=1;i<=o;++i)printf("%d ",q.front()),q.pop_front();
    for(int i=1;i<o;++i)printf("%d ",i);
    printf("%d\n",o);
    //system("pause");
    return 0;
}
