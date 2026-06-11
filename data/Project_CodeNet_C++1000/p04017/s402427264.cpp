#include <bits/stdc++.h>

#define N_MAX 100002
#define B_MAX 18

using namespace std;

int n, step, k;

int x[N_MAX];

int dp[N_MAX][B_MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> x[i];
    cin >> step >> k;
    for(int i = 1; i < n; i++)
    {
        int l = i, r = n;
        while(l < r)
        {
            int mid = (l + r + 1) / 2;
            if(x[mid] - x[i] > step)
                r = mid - 1;
            else
                l = mid;
        }
        dp[i][0] = l;
    }
    dp[n][0] = n + 1;
    for(int bit = 1; bit <= 16; bit++)
    {
        for(int i = 1; i < n; i++)
        {
            if(dp[i][bit - 1] == n + 1)
                dp[i][bit] = n + 1;
            else
                dp[i][bit] = dp[dp[i][bit - 1]][bit - 1];
        }
        dp[n][bit] = n + 1;
    }
    while(k--)
    {
        int a, b;
        cin >> a >> b;
        if(a > b)
            swap(a, b);
        int ans = 0;
        for(int bit = 16; bit >= 0 && a < b; bit--)
            if(dp[a][bit] <= b)
            {
                ans += (1 << bit);
                a = dp[a][bit];
            }
        if(a < b)
            ans++;
        cout << ans << "\n";
    }
    return 0;
}
