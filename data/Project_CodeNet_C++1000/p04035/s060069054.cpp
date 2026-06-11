#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

const long long MAXN = 1e5 + 21, inf = 1e18 + 21, LG = 20;

int n, l;
int a[MAXN];
pair <int, int> dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> l;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        dp[i] = make_pair(a[i] + a[i - 1], i);
    sort(dp + 1, dp + n);

    if (l > dp[n - 1].ff)
        return cout << "Impossible" << '\n', 0;

    cout << "Possible" << '\n';
    
    for (int i = 1; i < dp[n - 1].ss; i++)
        cout << i << '\n';

    for (int i = n - 1; i >= dp[n - 1].ss; i--)
        cout << i << '\n';
    
    return 0;
}
