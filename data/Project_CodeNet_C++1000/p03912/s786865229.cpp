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
const ll LINF = (ll)(1e18 + 99);
vector<ll> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
//cin.tie(0);ios::sync_with_stdio(false);

signed main()
{
    ll n, m, ans = 0;
    cin >> n >> m;
    vector<vector<ll>> v(m, vector<ll>(0));
    vector<ll> nofs(m, 0);

    rep(i, n)
    {
        ll x;
        cin >> x;
        v.at(x % m).pb(x);
    }
    rep(i, m)
    {
        sort(all(v[i]));
        
        rep(j,siz(v[i])){
            if(j<siz(v[i])-1 && v[i][j]==v[i][j+1]){
                nofs[i]++;
                j++;
            }
        }

        //cout<<siz(v[i])<<" "<<nofs[i]<<endl;
    }

    for (int i = 1; i < m - i; i++)
    {
        ll a = siz(v[i]), b = siz(v[m - i]);
        if (a <= b)
        {
            ans += a;
            ans += min(nofs[m - i], (b - a) / 2);
        }
        else
        {
            ans += b;
            ans += min(nofs[i], (a - b) / 2);
        }
    }

    ans+=siz(v[0])/2;
    if(m%2==0){
        ans+=siz(v[m/2])/2;
    }
    cout << ans << endl;
}