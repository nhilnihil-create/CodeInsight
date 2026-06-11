#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;
 
int main() {
    ll a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    a *= 100, b *= 100;

    ll ans1 = 0, ans2 = 0;
    double maxNoudo = 0.0;
    exrep(x1, 0, f/a) {
        exrep(x2, 0, (f - a*x1)/b) {
            ll mizu = a*x1 + b*x2;
            if(mizu == 0) {
                continue;
            }
            ll lim = (mizu/100)*e;
            exrep(y1, 0, lim/c) {
                exrep(y2, 0, (lim - c*y1)/d) {
                    ll satou = c*y1 + d*y2;
                    if(mizu + satou > f) {
                        continue;
                    }
                    double noudo = (double)(100*satou)/(double)(mizu + satou);
                    if(maxNoudo <= noudo) {
                        maxNoudo = noudo;
                        ans1 = mizu + satou;
                        ans2 = satou; 
                    }
                }
            }
        }
    }
    
    cout << ans1 << " " << ans2 << endl;
    re0;
}