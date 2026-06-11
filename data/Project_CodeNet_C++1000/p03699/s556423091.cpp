#include <bits/stdc++.h>
#define int long long
#define rng(i, l, r) for (size_t i = (l); i < (r); ++i)
#define rep(i, n) rng(i, 0, n)
#define gnr(i, l, r) for (size_t i = (r)-1; i >= (l); i--)
#define per(i, b) gnr(i, 0, b)
#define ALL(obj) (obj).begin(), (obj).end()    //1,2,3,...
#define rALL(obj) (obj).rbegin(), (obj).rend() //...,3,2,1
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
using namespace std;
const int INF = 1e18;

void solve()
{

    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int s[n];
    rep(i, n) cin >> s[i];

    int sum = 0;
    rep(i, n) sum += s[i];

    vector<vector<bool>> dp(n + 1, vector<bool>(10010, false));

    rep(i, n + 1) dp[i][0] = true;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < 10010; j++)
        {
            if (dp[i - 1][j])
            {
                dp[i][j] = true;
                if (j + s[i - 1] < 10010)
                    dp[i][j + s[i - 1]] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 10010; i++)
    {
        if (dp[n][i])
        {
            ans = max(ans, (i % 10) ? i : 0);
        }
    }

    cout << ans << endl;
}

signed main()
{
    solve();
    return 0;
}
