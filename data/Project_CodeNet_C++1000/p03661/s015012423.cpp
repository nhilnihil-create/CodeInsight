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
#pragma warning(disable:4996) 
 
typedef long long ll;
#define MIN(a, b) ((a)>(b)? (b): (a))
#define MAX(a, b) ((a)<(b)? (b): (a))
#define LINF  9223300000000000000
#define LINF2 1223300000000000000
#define INF 2140000000
const long long MOD = 1000000007;
//const long long MOD = 998244353;

using namespace std;

void solve()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    vector<ll> s(n + 1);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s[i + 1] = s[i] + a[i];
    }
    ll ans = LINF;
    for (i = 1; i < n; i++) {
        ans=MIN(ans, abs(s[n] - s[i]*2));
    }
    printf("%lld\n", ans);
    return;
}

int main(int argc, char* argv[])
{
#if 1
    solve();
#else
    int T;
    scanf("%d%d", &T, &B);
    int t;
    for(t=0; t<T; t++) {
        //printf("Case #%d: ", t+1);
        solve();
    }
#endif
    return 0;
}

