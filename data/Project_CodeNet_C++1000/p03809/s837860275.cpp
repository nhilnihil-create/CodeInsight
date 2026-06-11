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
int n,a[100005],r[100005],R;
vector<int> v[100005];
void dfs(int x,int y){
    if(v[x].size()==1){
        r[x]=a[x];
        return;
    }
    int cnt=0,mx=0;
    for(int i=0;i<v[x].size();++i){
        int z=v[x][i];
        if(z!=y){
            dfs(z,x);
            cnt+=r[z];
            mx=max(mx,r[z]);
        }
    }
    if(cnt<a[x]||a[x]*2<cnt||mx>a[x]){
        puts("NO");
        exit(0);
    }
    r[x]=a[x]*2-cnt;
    return;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",a+i);
    for(int i=1;i<n;++i){
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].pb(y),v[y].pb(x);
    }
    if(n==2){
        if(a[1]==a[2])puts("YES");
        else puts("NO");
        return 0;
    }
    for(int i=1;i<=n;++i)if(v[i].size()>1)R=i;
    dfs(R,0);
    if(r[R])puts("NO");
    else puts("YES");
    //system("pause");
    return 0;
}
