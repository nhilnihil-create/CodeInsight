#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n, m;
    cin >> n;
    vector<int> t(n);
    rep(i, n) cin >> t[i];
    cin >> m;
    vector<int> p(m), x(m);
    rep(i, m) cin >> p[i] >> x[i];

    int tmp=0;
    rep(i, n) tmp += t[i];

    rep(i, m)
    {
        int ans = tmp;
        ans -= t[p[i] - 1];
        ans += x[i];

        cout << ans << '\n';
    }

    return 0;
}
