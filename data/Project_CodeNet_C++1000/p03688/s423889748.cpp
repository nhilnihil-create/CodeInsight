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
    vector<int> a(n);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    int diff = a[n-1]-a[0];
    if (diff > 1) {
        printf("No\n");
    }
    else if (diff == 1) {
        int cnt = 0;
        for (i = 0; i < n; i++) {
            if (a[0] == a[i]) cnt++;
        }
        if (n-cnt >= (a[n - 1] - cnt) * 2 && (a[n - 1] - cnt) > 0) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    else {
        if (a[0] == n - 1) {
            printf("Yes\n");
        }
        else if (n >= a[0] * 2) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
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
