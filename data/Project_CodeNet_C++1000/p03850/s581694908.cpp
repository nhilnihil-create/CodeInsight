#include <bits/stdc++.h>
using namespace std;
int a[100002];
long long dp[100002][3];
char s[2];
int main(){
    int n;
    scanf("%d", &n);
    scanf("%d", &a[1]);

    for(int i=1;i<=n;i++) dp[i][0] = dp[i][1] = dp[i][2] = -1e14;
    dp[1][0] = a[1];

    for(int i=2;i<=n;i++){
        scanf("%s", s);
        scanf("%d", &a[i]);
        if(s[0] == '-'){
            dp[i][0] = max(dp[i-1][0] - a[i], dp[i-1][1] + a[i]);
            dp[i][1] = max(dp[i-1][0] - a[i], max(dp[i-1][1] + a[i], dp[i-1][2] - a[i]));
            dp[i][2] = max(dp[i-1][2] - a[i], dp[i-1][1] + a[i]);
        }
        else{
            dp[i][0] = max(dp[i-1][0] + a[i], dp[i-1][1] + a[i]);
            dp[i][1] = max(dp[i-1][1] - a[i], dp[i-1][2] + a[i]);
            dp[i][2] = dp[i-1][2] + a[i];
        }
    }   
    printf("%lld\n", max(max(dp[n][0], dp[n][1]), dp[n][2]));
}