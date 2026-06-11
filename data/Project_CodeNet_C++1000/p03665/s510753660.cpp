#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, p;  cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<long long> > dp(n+1, vector<long long>(2, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i+1][(a[i] + j) % 2] += dp[i][j];
            dp[i+1][j] += dp[i][j];
        }
    }
    cout << dp[n][p] << endl;
    return 0;
}