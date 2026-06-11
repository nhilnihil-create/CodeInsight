#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <assert.h>
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF 9223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;


void solve()
{
    int n, L;
    scanf("%d%d", &n, &L);
    vector<ll> a(n);
    ll max = -LINF;
    int maxi = 0;
    int i;
    for (i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (i > 0 && max < a[i] + a[i - 1]) {
            max = a[i] + a[i - 1];
            maxi = i;
        }
    }
    if (max >= L) {
        printf("Possible\n");
        for (i = 1; i < maxi; i++) {
            printf("%d\n", i);
        }
        for (i = n - 1; i > maxi; i--) {
            printf("%d\n", i);
        }
        printf("%d\n", maxi);
    }
    else {
        printf("Impossible\n");
    }

    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
#endif
    return 0;
}
