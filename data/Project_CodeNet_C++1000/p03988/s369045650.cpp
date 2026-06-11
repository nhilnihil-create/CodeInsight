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

void solve()
{
    int n;
    scanf("%d", &n);
    vector<int> cnt(n);
    int max = 0;
    int i;
    for (i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        cnt[tmp]++;
        max = MAX(max, tmp);
    }
    int bad = 0;
    if (max % 2) {
        for (i = 0; i <= max; i++) {
            if (i < (max+1) / 2) {
                if (cnt[i]) {
                    bad = 1;
                    break;
                }
            }
            else if (i == (max + 1) / 2) {
                if (cnt[i] != 2) {
                    bad = 1;
                    break;
                }
            }
            else {
                if (cnt[i] == 0) {
                    bad = 1;
                    break;
                }
            }
        }
    }
    else {
        for (i = 0; i <= max; i++) {
            if (i < max / 2) {
                if (cnt[i]) {
                    bad = 1;
                    break;
                }
            }
            else if (i == max / 2) {
                if (cnt[i] != 1) {
                    bad = 1;
                    break;
                }
            }
            else {
                if (cnt[i] == 0) {
                    bad = 1;
                    break;
                }
            }
        }
    }
    if (bad) {
        printf("Impossible\n");
    }
    else {
        printf("Possible\n");
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
