#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
typedef long long ll;
typedef pair<int, int> Pint;
typedef pair<ll, ll> Pll;
#define rep(begin, i, end) for (ll i = begin; i < (ll)(end); i++)
#define all(v) v.begin(), v.end()
const int MOD = 998244353;

int main()
{
    ll W, H, N;
    cin >> W >> H >> N;
    vector<vector<ll>> grid(H, vector<ll>(W, 1));
    ll x, y, a;
    rep(0, i, N)
    {
        cin >> x >> y >> a;
        if (a == 1)
        {
            ll s = 0, g = x;
            rep(0, i, H)
            {
                rep(s, j, g)
                {
                    grid.at(i).at(j) = 0;
                }
            }
        }
        if (a == 2)
        {
            ll s = x, g = W;
            rep(0, i, H)
            {
                rep(s, j, g)
                {
                    grid.at(i).at(j) = 0;
                }
            }
        }
        if (a == 3)
        {
            ll s = 0, g = y;
            rep(s, i, g)
            {
                rep(0, j, W)
                {
                    grid.at(i).at(j) = 0;
                }
            }
        }
        if (a == 4)
        {
            ll s = y, g = H;
            rep(s, i, g)
            {
                rep(0, j, W)
                {
                    grid.at(i).at(j) = 0;
                }
            }
        }
    }

    ll ans = 0;
    rep(0, i, H)
    {
        rep(0, j, W)
        {
            ans += grid.at(i).at(j);
        }
    }

    cout << ans << endl;
}