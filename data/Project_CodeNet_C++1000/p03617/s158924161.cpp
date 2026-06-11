#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
ll Q, H, S, D, N;
double a[4] = {0.25, 0.5, 1, 2};
ll ans = 0;
int main()
{
    cin >> Q >> H >> S >> D >> N;
    ll FQ = Q * 4;
    ll DH = H * 2;
    ll M = min(FQ, min(DH, S));

    // cout << M << endl;
    if (2 * M < D)
    {
        ans = N * M;
    }
    else
    {
        ans = (N / 2) * D;
        ans += (N % 2) * M;
    }
    cout << ans << endl;
    return 0;
}
