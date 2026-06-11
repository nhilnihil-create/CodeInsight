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

ll f[MX];

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    f[0] = 1;
    FOR(i,1,MX) f[i] = (f[i-1]*i*1LL)%MOD;

    int N, M; cin >> N >> M;

    if (abs(N-M) > 1) {
        cout << "0\n";
    } else if (abs(N-M) == 1) {
        cout << (f[N]*f[M]*1LL)%MOD;
    } else {
        cout << (((f[N]*f[M]*1LL)%MOD)*2LL)%MOD << "\n";
    }

}
