#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>


using namespace std;


#define mp make_pair
#define pb push_back
#define ll long long

#define maxN 100011
#define inf 1LL << 55

int n, i;
ll a[maxN];
char op[maxN];

ll dp[maxN][3];

int main() {
    
    scanf("%d", &n);
    for (i = 1; i < n; i++) 
        scanf("%lld %c", &a[i], &op[i + 1]);
    scanf("%lld", &a[n]);

    for (i = 0; i <= n; i++)
        dp[i][0] = dp[i][1] = dp[i][2] = -inf;
        
    op[1] = '+';
    dp[0][0] = 0;
    for (i = 1; i <= n; i++) {
        if (op[i] == '+') {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + a[i];
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]) - a[i];
            dp[i][2] = dp[i - 1][2] + a[i];
        } else {
            dp[i][1] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) - a[i];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
        }
    }
    
    ll ans = max(dp[n][0], max(dp[n][1], dp[n][2]));
    printf("%lld", ans);
    
    
    return 0;
}