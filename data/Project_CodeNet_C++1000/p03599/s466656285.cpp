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
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    int n = 30;
    int i, j;
    vector<int> flag(n + 1);
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= n; j++) {
            int tmp=i*a + j * b;
            if (tmp <= n) flag[tmp] = 1;
        }
    }
    vector<int> flag2(e*n + 1);
    flag2[0] = 1;
    for (i = 0; i <= e*n; i++) {
        if (flag2[i]) {
            if (i + c <= e * n) {
                flag2[i + c] = 1;
            }
            if (i + d <= e * n) {
                flag2[i + d] = 1;
            }
        }
    }
    vector<int> z;
    for (i = 0; i <= e * n; i++) {
        if (flag2[i]) z.push_back(i);
    }

    long double ans = -1;
    const long double eps = 1e-10;
    int ians = 0, valans = 0;
    for (i = 0; i <= n; i++) {
        if (flag[i] == 0) continue;
        
        int mm=MIN(i*e, f-100 * i);

        int k=lower_bound(z.begin(), z.end(), mm + 1) - z.begin();
        k--;
        int val=z[k];
        long double tmp = (long double)val / ((long double)100*i + val);
        if (tmp > ans+eps) {
            ans = tmp;
            ians = i;
            valans = val;
        }
    }

    printf("%d %d\n", ians * 100 + valans, valans);


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
        printf("Case #%d: ", t+1);
        solve();
    }
#endif
    return 0;
}

