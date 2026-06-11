#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 100002;

int n, k;

ll a[N_MAX];

ll sp[N_MAX];

ll spp[N_MAX];

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        sp[i] = sp[i - 1] + a[i];
    for(int i = 1; i <= n; i++)
        spp[i] = spp[i - 1] + a[i] * (a[i] > 0);
    ll ans = 0;
    for(int i = k; i <= n; i++)
        ans = max(ans, spp[n] - spp[i] + spp[i - k] + max(0LL, sp[i] - sp[i - k]));
    cout << ans << "\n";
    return 0;
}
