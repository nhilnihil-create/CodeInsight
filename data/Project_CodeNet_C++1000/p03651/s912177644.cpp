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

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}

void solve()
{
    int n, K;
    scanf("%d%d", &n, &K);
    int curr = 0, max = 0;
    int i;
    for (i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        max = MAX(max, tmp);
        curr = gcd(curr, tmp);
    }
    if (K > max) {
        printf("IMPOSSIBLE\n"); return;
    }
    if ((max - K) % curr == 0) {
        printf("POSSIBLE\n");
    }
    else {
        printf("IMPOSSIBLE\n");
    }



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
