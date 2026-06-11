#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;

int N, M;
int arr[MAXN];
ll sps[MAXN];
ll dps[MAXN]; // diff in adds
ll ans[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < MAXN; i++)
        sps[i] = dps[i] = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int l = arr[i], r = arr[i+1];
        if (l < r) l += M;
        r += M;
        sps[r-M+1] += (r - l);
        dps[l+1]--;
        dps[r+1]++;
    }

    ans[0] = 0;
    for (int i = 1; i <= 2 * M; i++)
    {
        sps[i] = sps[i] + dps[i-1];
        dps[i] = dps[i] + dps[i-1];
        ans[i] = ans[i-1] + sps[i];
    }

    for (int i = 1; i <= M; i++)
        ans[i] += ans[M+i];

    ll res = 1e18;
    for (int i = 1; i <= M; i++)
        res = min (res, ans[i]);
    cout << res << "\n";
}