#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define siz(v) (ll)(v).size()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, x, n) for (ll i = x; i < (ll)(n); i++)
#define lb lower_bound
#define ub upper_bound
typedef pair<int, int> P;
typedef pair<ll, ll> PL;
const ll mod = 1000000007;
const ll INF = 1000000099;
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
//cin.tie(0);ios::sync_with_stdio(false);

signed main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n) cin >> v[i];

    sort(all(v));

    ll dif = v.back() - v[0];

    if (dif > 1)
    {
        puts("No");
    }
    else if (dif == 0)
    {
        if (v[0] == n - 1 || v[0]<= n/2)
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    else
    {
        ll nofa = (lb(all(v), v[n - 1]) - v.begin());
        ll nofgm=n-nofa;
        if (nofgm>=2 && (v[n-1]-nofa)<=nofgm/2 && nofa<v[n-1])
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
}