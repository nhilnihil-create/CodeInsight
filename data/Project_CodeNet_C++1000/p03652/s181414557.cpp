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
bool b[305];
int n,m,ans,a[305][305],B,cnt[305],k[305];
int main(){
    scanf("%d%d",&n,&m);
    ans=n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)scanf("%d",a[i]+j);
        k[i]=1;
    }
    ans=n;
    while(B<m){
        memset(cnt,0,sizeof(cnt));
        int o=0;
        for(int i=1;i<=n;++i){
            while(b[a[i][k[i]]])++k[i];
            int _=a[i][k[i]];
            ++cnt[_];
            if(cnt[_]>o)o=cnt[_];
        }
        ans=min(ans,o);
        for(int i=1;i<=m;++i)if(cnt[i]==o)++B,b[i]=1;
    }
    printf("%d\n",ans);
    //system("pause");
    return 0;
}
