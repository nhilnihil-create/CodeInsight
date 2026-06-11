#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N;
int arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    ll ctot = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        ctot += arr[i];
    }

    ll ans = 1e18, mtot = 0;
    for (int i = 0; i < N - 1; i++)
    {
        mtot += arr[i];
        ans = min (ans, abs (ctot - 2 * mtot));
    }
    cout << ans << "\n";
}