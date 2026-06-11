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
int n,m,x[105],X,y[105],Y;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        int _;
        scanf("%d",&_);
        if(_&1)x[++X]=_;
        else y[++Y]=_;
    }
    if(m==1){
        if(n==1){
            printf("1\n1\n1\n",n);
        }
        else{
            printf("%d\n2\n%d 1\n",n,n-1);
        }
    }
    else if(X>2){
        puts("Impossible");
    }
    else if(X==2){
        if(x[1]==1){
            printf("%d ",x[1]);
            for(int i=1;i<=m-2;++i)printf("%d ",y[i]);
            printf("%d\n",x[2]);
            printf("%d\n",m-1);
            for(int i=1;i<=m-2;++i)printf("%d ",y[i]);
            printf("%d\n",x[2]+1);
        }
        else{
            printf("%d ",x[1]);
            for(int i=1;i<=m-2;++i)printf("%d ",y[i]);
            printf("%d\n",x[2]);
            printf("%d\n",m);
            printf("%d ",x[1]-1);
            for(int i=1;i<=m-2;++i)printf("%d ",y[i]);
            printf("%d\n",x[2]+1);
        }
    }
    else if(X==1){
        printf("%d ",x[1]);
        for(int i=1;i<m-1;++i)printf("%d ",y[i]);
        printf("%d\n",y[m-1]);
        printf("%d\n",m);
        printf("%d ",x[1]+1);
        for(int i=1;i<m-1;++i)printf("%d ",y[i]);
        printf("%d\n",y[m-1]-1);
    }
    else{
        for(int i=1;i<m;++i)printf("%d ",y[i]);
        printf("%d\n",y[m]);
        printf("%d\n",m);
        printf("%d ",y[1]+1);
        for(int i=2;i<m;++i)printf("%d ",y[i]);
        printf("%d\n",y[m]-1);
    }
    //system("pause");
    return 0;
}
