#include <iostream>
#include <vector>
#include <map>
#include <string>
using Int = long long int;
using UInt = unsigned long long int;
using namespace std;

int main(void) {
    const static Int MAX_XI_VALUE = 50;
    Int n, a;
    cin >> n >> a;

    vector<vector<vector<Int>> > dp(n + 1, vector<vector<Int> >(n + 1, vector<Int>(n * MAX_XI_VALUE + 1)));

    Int now;
    cin >> now;
    dp[1][1][now] = 1;

    for (Int i = 2; i <= n; ++i) {
        cin >> now;
        dp[i][1][now] = 1;
        for (Int j = 1; j <= i; ++j) {
            for (Int k = 1; k < n * MAX_XI_VALUE + 1; ++k) {
                dp[i][j][k] += dp[i - 1][j][k];
                if (k >= now) {
                    dp[i][j][k] += dp[i - 1][j - 1][k - now];
                }
            }
        }
    }

/*
    cout << "RESULT" << endl;
    for (Int i = 1; i <= n; ++i) {
        for (Int j = 1; j <= n; ++j) {
            for (Int k = 1; k < n * MAX_XI_VALUE + 1; ++k) {
                cout << i << " " << j << " " << k << endl;
                cout << dp[i][j][k] << endl;
            }
        }
    }
*/

    Int result = 0;
    for (Int j = 1; j <= n; ++j) {
        result += dp[n][j][a * j];
    }
    cout << result << endl;

    return 0;
}
