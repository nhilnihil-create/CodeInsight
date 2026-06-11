#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define int long long int
#define double long double
#define inf (int)(1e15)
#define all(x) (x).begin(), (x).end()
#define pair pair<int, int>
typedef vector<int> vi;   // Vector of long long
typedef vector<vi> vvi;   // Vector of vi
typedef vector<pair> vii; // Vector of pairs
typedef vector<vii> vvii; // Vector of Vector of pairs
typedef vector<bool> vb;  // Vector of bool
#define pq priority_queue // Max heap (To convert to min heap, use negative sign before every value)
#define ff first          // For pairs
#define ss second
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, -1, 0, 1};
const int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}, dy8[] = {1, -1, 1, 0, -1, 1, -0, -1};
#define testcases(t) \
    int(t);          \
    cin >> (t);      \
    while ((t)--)
signed main()
{
    int n, p;
    cin >> n >> p;
    vi a(n + 1);
    vvi dp(n + 1, vi(2));
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] % 2)
        {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][1] + dp[i - 1][0];
        }
        else
        {
            dp[i][0] = 2 * (dp[i - 1][0]);
            dp[i][1] = 2 * (dp[i - 1][1]);
        }
    }
    cout << dp[n][p] << endl;
    return 0;
}