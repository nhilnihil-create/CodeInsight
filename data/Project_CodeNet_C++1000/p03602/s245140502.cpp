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

int a[300][300];

int main(void) {
    int i, j, k, n;
    scanf("%d",&n);
    REP (i,n) REP (j,n) scanf("%d",&a[i][j]);

    long long ans = 0;
    REP (i,n) REP (j,i) ans += a[i][j];
    REP (i,n) REP (j,i) REP (k,n) if (k != i && k != j) {
        if (a[i][k] + a[k][j] == a[i][j]) {
            ans -= a[i][j];
            break;
        }
        else if (a[i][k] + a[k][j] < a[i][j]) {
            puts("-1");
            return 0;
        }
    }
    printf("%lld\n",ans);
    return 0;
}