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

char str[105];

void solve()
{
    scanf("%s", str);
    int n = strlen(str);
    
    int ans = INF;
    int k;
    for (k = 0; k < 26; k++) {
        int max = 0;
        int i;
        int prev = -1;
        for (i = 0; i <= n; i++) {
            if (i==n || str[i] == 'a' + k) {
                int tmp=(i - prev);
                max=MAX(max, tmp);
                prev = i;
            }
        }
        ans = MIN(ans, max);
    }
    printf("%d\n", ans-1);

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
