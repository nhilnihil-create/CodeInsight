/*---------------Go Code GO---------------*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using Order_Set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//(order) Set.order_of_key(); (pointer) Set.find_by_order();

#define PI acos(-1.0)
#define O_O                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define precision(a) fixed << setprecision(a)
#define endl '\n'
#define Flush cout << flush
#define LLMX 0x3fffffffffffffff

long long N;

int main()
{
    O_O;
    long long N, K;
    long long gcd, k, mx = 0;
    cin >> N >> K;
    cin >> gcd;
    mx = gcd;

    for (int i = 1; i < N; i++)
    {
        cin >> k;
        mx = max(mx, k);
        gcd = __gcd(gcd, k);
    }
    if (K > mx)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    if (K%gcd==0)
        cout << "POSSIBLE" << endl;
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}