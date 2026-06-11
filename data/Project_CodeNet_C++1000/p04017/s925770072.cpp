#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    int l, q;
    cin >> l >> q;
    vector<vector<int>> dp(31, vector<int>(n+1));
    for(int i = 0; i < n; i++)
    {
        int now = x[i];
        dp[0][i+1] = lower_bound(x.begin(), x.end(), now + l + 1) - x.begin();
    }
    dp[0][n] = -1;
    for(int k = 0; k < 30; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            if(dp[k][i] == -1) dp[k+1][i] = -1;
            else dp[k+1][i] = dp[k][dp[k][i]];
        }
    }
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        int left = min(a, b);
        int right = max(a, b);
        int ans = 0;
        for(int k = 30; k >= 0; k--)
        {
            int next = dp[k][left];
            if(next >= 0 && next < right)
            {
                left = next;
                ans |= 1 << k;
            }
        }
        ans++;
        cout << ans << endl;
    }
}