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
int n,m,q,f[100005][12],t[100005][12];
vector<int> v[100005];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].pb(y),v[y].pb(x);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        f[x][y]=z,t[x][y]=i;
    }
    for(int k=10;k;--k){
        for(int i=1;i<=n;++i){
            if(t[i][k-1]<t[i][k])t[i][k-1]=t[i][k],f[i][k-1]=f[i][k];
            for(int j=0;j<v[i].size();++j){
                int o=v[i][j];
                if(t[o][k-1]<t[i][k])t[o][k-1]=t[i][k],f[o][k-1]=f[i][k];
            }
        }
    }
    for(int i=1;i<=n;++i)printf("%d\n",f[i][0]);
    //system("pause");
    return 0;
}
