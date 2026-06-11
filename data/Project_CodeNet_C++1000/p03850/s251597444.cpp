// Math = ♥
// Sometimes it is people that no one imagines anything of who do things that no one can imagine
// After all this time? Always

#include <bits/stdc++.h>                        // uncomment before submission
//#include <ext/pb_ds/assoc_container.hpp>		// uncomment before submission
//#include <ext/pb_ds/tree_policy.hpp>			// uncomment before submission
//using namespace __gnu_pbds;					// uncomment before submission
using namespace std;
//<---------------------------------------------------Template----------------------------------------------------------->
#define int long long
#define ll long long
#define ld long double
int INF = 1e15 + 7;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;                  // Vector of long long
typedef vector<vi> vvi;                 // Vector of vi
typedef vector<ii> vii;                 // Vector of pairs
typedef vector<vii> vvii;               // Vector of Vector of pairs
typedef vector<bool> vb;                // Vector of bool
#define pq priority_queue               // Max heap (To convert to min heap, use negative sign before every value)
#define ff first                        // For pairs
#define ss second                       // For pairs
#define pb push_back                    // Pushback to vector
#define mp make_pair                    // Makes pairs to be stored as pair
#define all(c) (c).begin(), (c).end()   // Mainly used by me in sorting
// ordered_set adds two new functions to set - (set).find_by_order([kth element based on zero indexing]) and order_of_key()
// order_of_key returns number of elements less that parameter. If element exists, that order is its index
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
//<----------------------------------------------------------------------------------------------------------------------->

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;

    vector<char> op;
    vi num;

    int x;
    cin >> x, num.pb(x);
    for (int i = 0; i < n - 1; i++)
    {
        char ch;
        cin >> ch >> x;
        op.pb(ch), num.pb(x);
    }

    vvi dp(n, vector<int>(3));
    dp[0][0] = num[0];
    dp[0][1] = -INF;
    dp[0][2] = -INF;

    for (int i = 1; i < n; i++)
    {
        if (op[i - 1] == '+')
        {
            dp[i][1] = dp[i - 1][1] - num[i];
            dp[i][2] = dp[i - 1][2] + num[i];
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + num[i];
        } else
        {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) - num[i];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + num[i];
            dp[i][0] = -INF;
        }
        dp[i][0] = max(dp[i][0], max(dp[i][1], dp[i][2]));
        dp[i][1] = max(dp[i][1], dp[i][2]);
    }

    int a[] = {dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]};
    sort(a, a + 3);

    cout << a[2] << endl;
    return 0;
}
