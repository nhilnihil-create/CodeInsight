#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>

using namespace std;

int n, k;
int a[5010];
int ans;

const long long MOD = 1e9 + 239;
long long dp[15111];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        if (b >= k)
        {
            n--;
            i--;
            continue;
        }
        a[i] = b;
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 3 * k; j >= a[i]; j--)
        {
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = a[i]; j <= 3 * k; j++)
        {
            dp[j] = (dp[j] + MOD - dp[j - a[i]]) % MOD;
        }
        int t = 0;
        for (int j = k - a[i]; j < k; j++) if (dp[j] != 0) t = 1;
        //cout << k - a[i] << " " << k << " " << t << endl;
        //for (int j = 0; j < 2 * k; j++) cout << dp[j] << " ";
        //cout << endl;
        if (t == 0)
            ans++;
        for (int j = 3 * k; j >= a[i]; j--)
        {
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
    }
    cout << ans;
}
