#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
int n, k;
ll a[115000];
char c[115000];
ll dp[115000][5];

int main()
{
    cin >> n;
    cin >> a[0];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 5; j++)
            dp[i][j] = -1e15;
    dp[0][0] = a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> c[i] >> a[i];
        if (c[i] == '+')
        {
            for (int k = 0; k < 5; k++)
            {
                for (int nk = 0; nk <= k; nk++)
                {
                    dp[i][nk] = max(dp[i][nk], dp[i - 1][k] + (k % 2 == 0 ? a[i] : -a[i]));
                }
            }
        }
        else
        {
            for (int k = 0; k < 4; k++)
            {
                for (int nk = 0; nk <= k + 1; nk++)
                {
                    dp[i][nk] = max(dp[i][nk], dp[i - 1][k] + (k % 2 == 0 ? -a[i] : a[i]));
                }
            }
        }
    }
    cout << dp[n - 1][0] << endl;
}
