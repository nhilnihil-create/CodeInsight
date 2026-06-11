#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
const int mod = 1e9 + 7;

int n, dp[N][N];
char s[N];

void add (int &x, int y) {
    x = (x + y) % mod;
}

int main(){
    scanf("%d", &n);
    scanf("%s", s);

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j]) {
                add(dp[i + 1][j + 1], dp[i][j]);
                if (j) add(dp[i + 1][j - 1], 1LL * 2 * dp[i][j] % mod);
                else add(dp[i + 1][j], dp[i][j]);
            }
        }
    }

    printf("%d", dp[n][strlen(s)]);
    return 0;
}

