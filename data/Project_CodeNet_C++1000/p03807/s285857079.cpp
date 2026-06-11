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
    long long i, j, k, l, tst = 0, ans = 0, csno = 0;
    long long odd = 0, even = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> k;
        odd += (k % 2);
        even += (k % 2 == 0);
    }
    if (odd % 2 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}