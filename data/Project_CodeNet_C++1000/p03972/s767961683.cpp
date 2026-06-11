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
#include <bitset>
#include <complex>
#include <cassert>
#define FOR(i,k,n)  for (int i=(k); i<(int)(n); ++i)
#define REP(i,n)    FOR(i,0,n)
#define FORIT(i,c)	for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(i) ((int)i.size())
#define GI(i) (scanf("%d",&i))
#define GLL(i) (scanf("%lld",&i))
#define GD(i)  (scanf("%lf",&i))
#define PB          push_back
#define MP          make_pair
#define MT          make_tuple
#define GET0(x)     (get<0>(x))
#define GET1(x)     (get<1>(x))
#define GET2(x)     (get<2>(x))
#define ALL(X)      (X).begin(),(X).end()
#define LLMAX       (1LL<<60)
#define LLMIN       -(1LL<<60)
#define IMAX        (1<<30)
#define IMIN        -(1<<30)
typedef long long LL;
using namespace std;

const int VERTICAL = 0;
const int HORIZONTAL = 1;

int main(void){
    LL W,H;
    GLL(W);GLL(H);
    vector<pair<LL,int> > edge;
    REP(i,W){
        LL p;
        GLL(p);
        edge.PB(MP(p,VERTICAL));
    }
    REP(i,H){
        LL q;
        GLL(q);
        edge.PB(MP(q,HORIZONTAL));
    }
    sort(ALL(edge));
    LL numHorizontal = 0;
    LL numVertical = 0;
    LL ans=0;
    for(auto e:edge){
        // printf("e.first=%lld e.second=%d\n",e.first,e.second);
        if(e.second==VERTICAL){
            ans+=(H+1-numHorizontal)*e.first;
            numVertical++;
        }else{
            ans+=(W+1-numVertical)*e.first;
            numHorizontal++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
