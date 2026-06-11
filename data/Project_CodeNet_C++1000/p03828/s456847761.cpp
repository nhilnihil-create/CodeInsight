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

    int N; cin >> N;

    unordered_map<ll,ll> m;
    FOR(w,1,N+1) {
        int X = w;
        FOR(i, 2, X+1) {
            if (i*i > X) break;
            if (X%i == 0) {
                ll exp = 0;
                while(X%i == 0) X /= i, exp++;
                m[i] += exp;
            }
        }
        if (X > 1) m[X]++;
    }

    ll ans = 1;
    trav(w, m) {
        ans = (ans*(w.s+1))%MOD;
    }

    cout << ans << "\n";
}
