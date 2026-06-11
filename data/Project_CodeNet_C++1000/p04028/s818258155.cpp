#include<algorithm>
#include<cstdio>
#include<cstring>

const int Maxv = 5005, INF = 0x6ffffff, MOD = 1e9 + 7; 
long long dp[Maxv][Maxv]; 
char c[Maxv]; 

inline int read(){
    int x = 0, f = 1; 
    char ch = getchar(); 
    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            f = -1; 
        }
        ch = getchar(); 
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + ch - '0'; 
        ch = getchar(); 
    }
    return x * f; 
}

int main(){
    int n = read(); 
    scanf("%s", c + 1); 
    int len = strlen(c + 1); 
    if (n < len) {
        printf("0\n"); 
        return 0; 
    }
    memset(dp, 0, sizeof(dp)); 
    dp[0][0] = 1; 
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j) {
                dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j]) % MOD; 
            }
            else {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD; 
            }
            dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j] * 2) % MOD; 
        }
    }
    for (int i = 1; i <= len; i++) {
        dp[n][len] = (dp[n][len] * 500000004) % MOD; 
    }
    printf("%d\n", dp[n][len]); 
    return 0; 
}