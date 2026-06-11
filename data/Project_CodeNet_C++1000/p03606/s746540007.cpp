#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    rep(i, n) cin >> l[i] >> r[i];

    int ans = 0;
    rep(i, n)
    {
        ans += r[i] - l[i] + 1;
    }
    cout << ans << "\n";

    return 0;
}
