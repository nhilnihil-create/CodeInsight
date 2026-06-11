#include <bits/stdc++.h> 

using namespace std;

#define YES cout << "YES" << endl;
#define NO  cout << "NO"  << endl;
#define Yes cout << "Yes" << endl;
#define No  cout << "No"  << endl;
 
#define INF INT_MAX
#define MOD 1000000007
#define PI  acos(-1)

using ll  = long long;
using ull = unsigned long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rrep(i, n) for (ll i = (n)-1; i >= 0; i--)

int main(int argc, char *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll H, W, N;
    cin >> H >> W >> N;

    vector<ll> a(N);
    rep (i, N) {
        cin >> a[i];
    }

    vector<ll> tmp;
    rep (i, N) {
        rep (j, a[i]) {
            tmp.push_back(i+1);
        }
    }

    vector<vector<ll>> ans(H, vector<ll>(W, 0));

    rep (i, H) {
        if (i%2) {
            rep(j, W) {
                ans[i][W-j-1] = tmp[i*W+j];
            }
        } else {
            rep(j, W) {
                ans[i][j] = tmp[i*W+j];
            }
        }
    }

    rep (i, H) {
        rep (j, W) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}