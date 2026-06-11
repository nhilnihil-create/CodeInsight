#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long int> dp(1001, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        int temp = i;
        for (int j = 2; j <= i; j++) {
            while (temp % j == 0) {
                dp[j]++;
                temp /= j;
            }
        }
    }

    long long int sum = 1;
    for (int i = 2; i <= n; i++) {
        sum *= (dp[i] + 1);
        sum = sum % 1000000007;
    }

    cout << sum << endl;
}