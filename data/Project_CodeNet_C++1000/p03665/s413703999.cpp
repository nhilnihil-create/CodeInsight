#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <iterator>
#include <cassert>
#include <numeric>
#include <functional>
#include <cassert>
//#include <numeric>
#pragma warning(disable:4996) 
 
typedef long long ll;
typedef unsigned long long ull;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

ll dp[55][2];

void solve()
{
    int n, p;
    scanf("%d%d", &n, &p);
    vector<int> a(n);
    dp[0][0] = 1;
    int i,k;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        for (k = 0; k < 2; k++) {
            dp[i + 1][k] += dp[i][k];
            dp[i + 1][(k + a[i]) % 2] += dp[i][k];
        }
    }
    printf("%lld\n", dp[n][p]);

    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T;
    scanf("%d", &T);
    int t;
    for(t=0; t<T; t++) {
        //printf("Case #%d: ", t+1);
        solve();
    }
#endif
    return 0;
}

