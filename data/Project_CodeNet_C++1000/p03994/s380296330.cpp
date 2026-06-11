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

char str[100005];

void solve()
{
    scanf("%s", str);
    int n = strlen(str);
    int K;
    scanf("%d", &K);
    ll sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        int tmp = ('a'-str[i] + 26) % 26;
        if (sum + tmp <= K) {
            sum += tmp;
            str[i] = 'a';
        }
        else {
            continue;
        }
    }
    for (i = n-1; i >=0; i--) {
        int tmp = ('a'-str[i] + 26) % 26;
        if (sum + tmp <= K) {
            sum += tmp;
            str[i] = 'a';
        }
        else {
            continue;
        }
    }
    {
        int tmp = (str[n - 1] - 'a' + (K - sum)) % 26;
        str[n - 1] = 'a' + tmp;
    }
    printf("%s\n", str);
    
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
