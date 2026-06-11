#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <random>
#include <cassert>
#include <cstring>
using namespace std;

#define GET_ARG(a,b,c,F,...) F
#define REP3(i,s,e) for (i = s; i <= e; i++)
#define REP2(i,n) REP3 (i,0,(int)(n)-1)
#define REP(...) GET_ARG (__VA_ARGS__,REP3,REP2) (__VA_ARGS__)
#define RREP3(i,s,e) for (i = s; i >= e; i--)
#define RREP2(i,n) RREP3 (i,(int)(n)-1,0)
#define RREP(...) GET_ARG (__VA_ARGS__,RREP3,RREP2) (__VA_ARGS__)
#define DEBUG(x) cerr << #x ": " << x << endl

typedef long long ll;

int a[100000], b[100000];

int main(void) {
    int i, n, k;
    scanf("%d%d",&n,&k);
    REP (i,n) scanf("%d%d",&a[i],&b[i]);

    ll ans = 0;
    REP (i,n) if (!(~k & a[i])) ans += b[i];
    for (; k > 0; k -= k & -k) {
        ll sum = 0;
        REP (i,n) if (!(~(k-1) & a[i])) sum += b[i];
        ans = max(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}