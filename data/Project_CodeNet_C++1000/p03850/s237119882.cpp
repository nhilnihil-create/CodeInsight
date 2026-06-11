// Math = ♥️

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

/*-------------------------------------------------------------------------------------------------------------------------*/
#define ll long long                  // Short form for long long
#define ld long double                // Short form for long double
typedef pair<ll, ll> ii;              // Pair of long long
typedef vector<ll> vi;                // Vector of long long
typedef vector<vi> vvi;               // Vector of vector of long long
typedef vector<ii> vii;               // Vector of pairs
typedef vector<vii> vvii;             // Vector of vector of pairs
#define pq priority_queue             // Max heap (To convert to min heap, use negative sign before every value)
#define ff first                      // For pairs
#define ss second                     // For pairs
#define pb push_back                  // Pushback to vector
#define mp make_pair                  // Makes pairs to be stored as pair
#define all(c) (c).begin(), (c).end() // Mainly used by me in sorting
// ordered_set adds two new functions to set - (set).find_by_order([kth element based on zero indexing]) and order_of_key()
// order_of_key returns number of elements less that parameter. If element exists, that order is its index
#define ordered_set tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
/*-------------------------------------------------------------------------------------------------------------------------*/
#define MAXN (ll)(1e5 + 5)
#define NIL (ll)(1e18 + 5)

ll dp[MAXN][3];
vector<char> op;
vi arr;
ll n;

ll solve(ll i, ll t)
{
    if (i == n - 1)
    {
        if (t == 0 || t == 2)
            return arr[i];
        else
            return -arr[i];
    }

    if (dp[i][t] == NIL)
    {
        if (t == 0)
        {
            if (op[i] == '-')
                dp[i][t] = solve(i + 1, 1) + arr[i];
            else
                dp[i][t] = solve(i + 1, 0) + arr[i];
        }
        else if (t == 1)
        {
            if (op[i] == '-')
                dp[i][t] = max(solve(i + 1, 1) - arr[i], solve(i + 1, 2) - arr[i]);
            else
                dp[i][t] = max(solve(i + 1, 1) - arr[i], solve(i + 1, 0) - arr[i]);
        }
        else
        {
            if (op[i] == '-')
                dp[i][t] = solve(i + 1, 2) + arr[i];
            else
                dp[i][t] = max(solve(i + 1, 2), max(solve(i + 1, 1), solve(i + 1, 0))) + arr[i];
        }
    }
    return dp[i][t];
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j] = NIL;

    cin >> n;

    arr.resize(n);
    op.resize(n - 1);
    cin >> arr[0];

    for (int i = 1; i < n; i++)
        cin >> op[i - 1] >> arr[i];

    cout << solve(0, 0) << "\n";
}
