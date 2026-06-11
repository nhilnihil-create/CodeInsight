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
int n,m,p[100005],q[100005],b[100005];
ll k,a[100005],s;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%lld",a+i);
    scanf("%d%lld",&m,&k);
    for(int i=n;i>1;--i)p[i]=i,a[i]-=a[i-1];
    while(m--){
        int x;
        scanf("%d",&x);
        swap(p[x],p[x+1]);
    }
    for(int i=2;i<=n;++i){
        if(q[i]) continue;
        int _=1,o=p[i];
        b[0]=i;
        while(o!=i)b[_++]=o,o=p[o];
        o=b[k%_];
        for(int j=i;!q[j];j=p[j])q[j]=o,o=p[o];
    }
    q[1]=1;
    for(int i=1;i<=n;++i){
        s+=a[q[i]];
        printf("%lld\n",s);
    }
    //system("pause");
    return 0;
}
