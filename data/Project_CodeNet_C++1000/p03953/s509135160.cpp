#include <iostream>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
#include <functional>
#include <cstring>
#include <limits.h>
#define FOR(i,k,n)  for (int i=(k); i<(int)(n); ++i)
#define REP(i,n)    FOR(i,0,n)
#define FORIT(i,c)	for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(i) ((int)i.size())
#define pb          push_back
#define mp          make_pair
#define mt          make_tuple
#define get0(x)     (get<0>(x))
#define get1(x)     (get<1>(x))
#define get2(x)     (get<2>(x))
#define ALL(X)      (X).begin(),(X).end()
#define LLMAX       9223372036854775807LL
#define LLMIN       -9223372036854775808LL
#define IMAX        2147483647
#define IMIN        -2147483648
typedef long long LL;
using namespace std;

int N,M,a[100000];
LL x[100000],d[100000],e[100000];
int sw[62][100000];
int ansp[100000];
int ansq[100000];
LL K;

int main(void){
    cin>>N;
    REP(i,N){
        cin>>x[i];
        if(0<i)
            d[i-1]=x[i]-x[i-1];
    }
    cin>>M>>K;
    REP(i,M){
        cin>>a[i];
        a[i]--;
    }

     REP(i,62){
         if(i==0){
             REP(j,N-1)
                 sw[i][j]=j;
             REP(j,M){
                 swap(sw[i][a[j]],sw[i][a[j]-1]);
             }
         }else{
             REP(j,N-1)
                 sw[i][j]=sw[i-1][sw[i-1][j]];
         }
     }
     REP(i,N-1)
         ansp[i]=i;
     REP(i,62)
         if((1LL<<(LL)i)&K){
             REP(j,N-1)
                 ansq[j]=sw[i][ansp[j]];
             REP(j,N-1)
                 ansp[j]=ansq[j];
         }
     REP(j,N-1)
         e[j]=d[ansp[j]];
     LL y=x[0];
     cout<<y<<endl;
     REP(i,N-1){
         y+=e[i];
         cout<<y<<endl;
     }
     return 0;
}
