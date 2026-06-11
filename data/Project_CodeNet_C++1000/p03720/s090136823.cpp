#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, a, b;
    cin >> n >> m;
    int dp[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) dp[i][j] = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        dp[a - 1][b - 1]++;
        dp[b - 1][a - 1]++;
    }
    for (int i = 0; i < n; i++) 
    {
        int k = 0;
        for (int j = 0; j < n; j++) k += dp[i][j];
        cout << k << endl;
    }
}