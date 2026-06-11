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
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();

    vl x(n);
    rep(i, n) {
        if(s[i] == 'A') {
            x[i] = 1;
        }
        else {
            x[i] = 2;
        }
    }

    vl y(m);
    rep(i, m) {
        if(t[i] == 'A') {
            y[i] = 1;
        }
        else {
            y[i] = 2;
        }
    }

    vl ruiX(n+1);
    rep(i, n) {
        ruiX[i+1] = ruiX[i] + x[i];
    }

    vl ruiY(m+1);
    rep(i, m) {
        ruiY[i+1] = ruiY[i] + y[i];
    }

    ll q;
    cin >> q;

    vl ans(q);
    rep(i, q) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;  c--;
        if( (ruiX[b] - ruiX[a])%3 == (ruiY[d] - ruiY[c])%3 ) {
            ans[i] = 1;
        }
    } 

    rep(i, q) {
        if(ans[i]) {
            out("YES");
        }   
        else {
            out("NO");
        }
    }
    
    re0;
}