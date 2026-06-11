#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<ll> vll;
typedef complex<double> cd;

#define forn(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define popcount(x) __builtin_popcount(x)
#define popcountll(x) __builtin_popcountll(x)
#define fi first
#define se second
#define re return
#define pb push_back
#define uniq(x) sort(all(x)); (x).resize(unique(all(x)) - (x).begin())

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " " << #x << " " << x << endl
#define ln cerr << __LINE__ << endl
#else
#define dbg(x) void(0)
#define ln void(0)
#endif // LOCAL

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    vector<int> odd;
    for (int i = 0; i < m; i++)
    {
        if (a[i] % 2 == 1)
        {
            odd.push_back(i);
        }
    }
    if (odd.size() > 2)
    {
        cout << "Impossible";
        return 0;
    }
    if (m == 1)
    {
        cout << a[0] << "\n";
        if (a[0] == 1) cout << 1 << "\n" << 1 << "\n";
        else cout << 2 << "\n" << a[0] - 1 << " " << 1 << "\n";
        return 0;
    }
    if (m == 2)
    {
        cout << a[0] << " " << a[1] << "\n";
        if (a[0] == 1) cout << 1 << "\n" << n << "\n";
        else cout << 2 << "\n" << a[0] - 1 << " " << a[1] + 1 << "\n";
        return 0;
    }
    vector<int> x;
    if (odd.size() > 0) x.push_back(a[odd[0]]);
    for (int i = 0; i < m; i++) if (a[i] % 2 == 0) x.push_back(a[i]);
    if (odd.size() > 1) x.push_back(a[odd[1]]);
    for (auto e : x) cout << e << " "; cout << "\n";
    vector<int> y;
    y.push_back(x[0] + 1);
    for (int i = 1; i < m - 1; i++) y.push_back(x[i]);
    if (x[m - 1] != 1) y.push_back(x[m - 1] - 1);
    cout << y.size() << "\n";
    for (auto e : y) cout << e << " "; cout << "\n";
}

/* Note:
Check constants at the beginning of the code.
    N is set to 4e5 but be careful in problems with large constant factor.
    Setting N in every problem is more effective.
Check corner cases.
    N = 1
No def int long long for now.
Add something here.
*/
