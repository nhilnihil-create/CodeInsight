#include<bits/stdc++.h>
using namespace std;
#define N 100000 + 5
#define M 15
#define inf 10000000000000000
#define int long long
#define rep(i, l, r) for(int i = l; i <= r; ++i)
char ch[M];
int n, len, a[N], op[N], dp[N][3];
int read(){
    char c; int x = 0, f = 1;
    c = getchar();
    while(c > '9' || c < '0'){ if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
signed main(){
    n = read();
    rep(i, 1, 2 * n - 1){
        if(i & 1) a[i / 2 + 1] = read();
        else{
            scanf("%s", ch + 1);
            if(ch[1] == '+') op[i / 2 + 1] = 1;
            else op[i / 2 + 1] = 2;
        }
    }
    dp[1][0] = a[1], dp[1][1] = dp[1][2] = -inf;
    rep(i, 2, n){
        if(op[i] == 1){
            dp[i][0] = dp[i - 1][0] + a[i];
            dp[i][0] = max(dp[i][0], dp[i - 1][1] - a[i]);
            dp[i][0] = max(dp[i][0], dp[i - 1][2] + a[i]);
            dp[i][1] = dp[i - 1][1] - a[i];
            dp[i][1] = max(dp[i][1], dp[i - 1][2] + a[i]);
            dp[i][2] = dp[i - 1][2] + a[i];
        }
        else{
            dp[i][0] = dp[i - 1][0] - a[i];
            dp[i][0] = max(dp[i][0], dp[i - 1][1] + a[i]);
            dp[i][0] = max(dp[i][0], dp[i - 1][2] - a[i]);
            dp[i][1] = dp[i - 1][1] + a[i];
            dp[i][1] = max(dp[i][1], dp[i - 1][2] - a[i]);
            dp[i][1] = max(dp[i][1], dp[i - 1][0] - a[i]);
            dp[i][2] = dp[i - 1][2] - a[i];
            dp[i][2] = max(dp[i][2], dp[i - 1][1] + a[i]);
        }
    }
    printf("%lld", dp[n][0]);
    return 0;
}