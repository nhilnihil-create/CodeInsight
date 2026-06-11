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
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m), ans(n, 0);
    rep(i, m) cin >> a[i] >> b[i];

    rep(i, m)
    {
        ans[a[i] - 1]++;
        ans[b[i] - 1]++;
    }

    rep(i, n) cout << ans[i] << endl;

    return 0;
}
