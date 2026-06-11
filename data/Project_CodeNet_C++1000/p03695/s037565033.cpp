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

ll v[20];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;

    F0R(i,N) {
        ll x; cin >> x;

        if (x <= 399)       v[1]++;
        else if (x <= 799)  v[2]++;
        else if (x <= 1199) v[3]++;
        else if (x <= 1599) v[4]++;
        else if (x <= 1999) v[5]++;
        else if (x <= 2399) v[6]++;
        else if (x <= 2799) v[7]++;
        else if (x <= 3199) v[8]++;
        else v[10]++;
    }


    ii res = {0,0};
    FOR(i,1,9) {
        if (v[i]) res.f++;
    }

    res.s = min(1000LL,res.f+v[10]);
    if (res.f == 0) res.f++;
    cout << res.f << " " << res.s << "\n";

}
