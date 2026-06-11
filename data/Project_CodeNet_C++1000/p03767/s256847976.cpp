#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
int N;
ll ans = 0;

int main()
{
    cin >> N;
    vector<ll> a(3 * N);
    rep(i, 0, 3 * N)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = N; i < 3 * N; i += 2)
    {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}
