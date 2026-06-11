#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cassert>
using namespace std;

#define GET_ARG(a,b,c,F,...) F
#define REP3(i,s,e) for (i = s; i <= e; i++)
#define REP2(i,n) REP3 (i,0,(int)(n)-1)
#define REP(...) GET_ARG (__VA_ARGS__,REP3,REP2) (__VA_ARGS__)
#define RREP3(i,s,e) for (i = s; i >= e; i--)
#define RREP2(i,n) RREP3 (i,(int)(n)-1,0)
#define RREP(...) GET_ARG (__VA_ARGS__,RREP3,RREP2) (__VA_ARGS__)
#define DEBUG(x) cerr << #x ": " << x << endl

int cnt[100001], even[100001], rest[100001];

int main(void) {
    int i, n, m;
    scanf("%d%d",&n,&m);
    REP (i,n) {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    REP (i,1,1e5) {
        even[i%m] += cnt[i]/2;
        rest[i%m] += cnt[i];
    }
    int ans = rest[0] / 2;
    REP (i,1,m-1) {
        int x;
        if (i != m-i) x = min(rest[i],rest[m-i]);
        else x = rest[i] / 2;
        ans += x;
        rest[i] -= x;
        rest[m-i] -= x;
    }
    REP (i,1,m-1) {
        ans += min(even[i],rest[i]/2);
    }
    printf("%d\n",ans);
    return 0;
}
