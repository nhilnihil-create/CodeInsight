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
int n,m,a[100005],A,B,C;
bool ok;
vector<int> v[100005];
void dfs(int x,int y){
    if(a[x]){
        if(a[x]!=y)ok=0;
        return;
    }
    a[x]=y;
    for(int i=0;i<v[x].size();++i)dfs(v[x][i],-y);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].pb(y),v[y].pb(x);
    }
    for(int i=1;i<=n;++i){
        if(a[i]) continue;
        if(!v[i].size()){
            ++A;
            continue;
        }
        ok=1;
        dfs(i,1);
        if(!ok)++C;
        else ++B;
    }
    printf("%lld\n",A*(n*2ll-A)+B*2ll+C+B*(B-1ll)*2ll+C*(C-1ll)+B*2ll*C);
    //system("pause");
    return 0;
}
