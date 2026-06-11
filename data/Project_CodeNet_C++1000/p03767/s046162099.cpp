#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int n;
    cin >> n;
    vector<int> a(3 * n);
    rep(i, 3 * n) cin >> a[i];

    sort(all(a));
    reverse(all(a));

    ll ans = 0;
    for (int i = 1; i <= 2 * n; i += 2)
    {
        ans += a[i];
    }

    cout << ans << endl;

    return 0;
}
