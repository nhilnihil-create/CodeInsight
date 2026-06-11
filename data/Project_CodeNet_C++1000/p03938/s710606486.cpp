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
    cin >> N;
    long long A[N + 4], B[N + 4], per[N + 4];

    for (int i = 1; i <= N; i++)
    {
        cin >> per[i];
    }
    for (long long i = 1; i <= N; i++)
    {
        A[i] = N * i;
    }
    for (long long i = N + 1; i <= 2 * N; i++)
    {
        B[i - N] = i * N;
    }
    reverse(B + 1, B + N + 1);
    long long base = A[1] + B[1];
    for (int i = 2; i <= N; i++)
    {
        A[per[i]] += i - 1;
    }
    for (int i = 1; i <= N; i++)
        cout << A[i] << ' ';
    cout << endl;
    for (int i = 1; i <= N; i++)
        cout << B[i] << ' ';
    cout << endl;
    return 0;
}