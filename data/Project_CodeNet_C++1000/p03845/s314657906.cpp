#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rem(i, m, n) for (int i = m; i < (n); i++)
#define eps (1e-7)
#define inf (1e9)
#define pi (acos(-1))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vi t(n);
    rep(i, n) cin >> t[i];
    int m;
    cin >> m;

    vi p(m), x(m);
    rep(i, m) cin >> p[i] >> x[i];

    int sum = 0;
    rep(i, n) sum += t[i];

    rep(i, m)
    {
        cout << sum - t[p[i] - 1] + x[i] << "\n";
    }

    return 0;
}