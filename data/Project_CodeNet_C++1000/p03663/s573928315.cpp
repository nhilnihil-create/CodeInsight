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

bool ask(ll tmp)
{
    printf("? %lld\n", tmp);
    fflush(stdout);
    char str[5] = { 0 };
    scanf("%s", str);
    if (str[0] == 'Y') {
        return true;
    }
    else {
        return false;
    }
}

void solve()
{
    int i;
    ll curr = 1;
    for (i = 1; i <= 10; i++) {
        if(i>1) curr = curr * 10;
        bool ok=ask(curr);
        if (!ok) {
            break;
        }
    }
    if (i == 11) {
        ll curr = 0;
        for (i = 1; i <= 10; i++) {
            curr = curr * 10 + 9;
            bool ok=ask(curr);
            if (ok) {
                break;
            }
        }
        //assert(i <= 9);
        int k;
        printf("! ");
        for (k = 0; k < i; k++) {
            if (k == 0) printf("1");
            else        printf("0");
        }
        printf("\n");
        fflush(stdout);
        return;
    }
    int keta = i-1;

    curr = 0;
    for (i = 1; i <= keta; i++) {
        int l = 0, r = 10;
        while (r - l > 1) {
            int m = (l + r) / 2;
            ll tmp0 = m;
            int k;
            for (k = 0; k < 9-(i-1); k++) {
                tmp0 *= 10;
            }
            ll tmp = curr + tmp0;
            bool ok = ask(tmp);
            if (ok) {
                r = m;
            }
            else {
                l = m;
            }
        }
        ll tmp0 = l;
        int k;
        for (k = 0; k < 9-(i-1); k++) {
            tmp0 *= 10;
        }
        curr += tmp0;
    }
    for (i = 1; i <= 9 - (keta - 1); i++) {
        curr /= 10;
    }
    printf("! %lld\n", curr+1);
    fflush(stdout);

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

