#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const ll inf = 1e15;
int n;
ll a[N], dp[N][3];
char s[N][2];
int main() {
    scanf("%d", &n);
    for(int i = 1; i < n; ++i) {
        scanf("%lld%s", &a[i], s[i]);
    }
    scanf("%lld", &a[n]);
    dp[1][0] = a[1];
    dp[1][1] = dp[1][2] = -inf; 
    for(int i = 2; i <= n; ++i) {
        if(s[i - 1][0] == '-') {
            dp[i][0] = -inf;
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) - a[i];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
        } else {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
            dp[i][1] = max(dp[i - 1][2], dp[i - 1][1]) - a[i];
            dp[i][2] = dp[i - 1][2] + a[i];
        }
    }
    printf("%lld\n", max(max(dp[n][0], dp[n][1]), dp[n][2]));
    return 0;
}