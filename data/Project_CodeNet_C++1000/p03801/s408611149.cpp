#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using ld = long double;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define siz(v) (ll)(v).size()
#define rep(i, a, n) for (ll i = a; i < (ll)(n); i++)
#define repr(i, a, n) for (ll i = n - 1; (ll)a <= i; i--)
#define lb lower_bound
#define ub upper_bound
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
const ll LINF = (ll)(1e18 + 99);
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
template <typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template <typename T>
T mpow(T a, T n)
{
    T res = 1;
    for (; n; n >>= 1)
    {
        if (n & 1)
            res = res * a;
        a = a * a;
    }
    return res;
}

//cin.tie(0);ios::sync_with_stdio(false);

signed main()
{
    int n;
    cin >> n;
    vector<ll> v(n), u(n, 0);
    rep(i, 0, n)
    {
        cin >> v[i];
        u[i] = v[i];
    }
    sort(all(u));

    ll ind = 0, mx = 0;
    rep(i, 0, n)
    {
        if (v[i] <= mx)
        {
            cout << 0 << endl;
        }
        else
        {
            ll sum=0;
            while (ind<n && u[ind] < v[i])
            {
                sum+=u[ind]-mx;
                ind++;
            }
            sum+=(n-ind)*(v[i]-mx);
            cout<<sum<<endl;
            mx=v[i];
        }
    }
}