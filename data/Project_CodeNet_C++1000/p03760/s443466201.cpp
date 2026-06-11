#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b); i >= (a); i--)
#define R0F(i, a) ROF(i, 0, a-1)
#define trav(x, a) for (auto& x: a)

const int MX  = 2e5+5;
const int MOD = 1e9+7;
const ll  INF = 1061109567; // 4557430888798830399LL
const ld  EPS = 1e-9;
const ld  PI  = acos(-1);

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string x,y; cin >> x >> y;

    F0R(i, min(sz(x),sz(y))) {
        cout << x[i] << y[i];
    }

    if (sz(x) == sz(y)) return 0;

    if (sz(x) > sz(y)) {
        cout << x[sz(x)-1];
    } else {
        cout << y[sz(y)-1];
    }

}
