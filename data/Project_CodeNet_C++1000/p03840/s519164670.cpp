#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1000000000;
const ll LINF = (ll) 4000000000000000000;
const ll MOD = (ll) 1000000007;
const double PI = acos(1.0);
const int limit = 100010;

#define REP(i,m,n) for(ll i = m; i < (ll)(n); ++i)
#define rep(i,n) REP(i, 0, n)
#define MP make_pair
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define NP(v) next_permutation(v.begin(),v.end())
#define smaller_queue  priority_queue <ll, vector<ll>, greater<ll> >
//------------------------------------------------------

int main() {
    ll I, O, T, J, L;
    cin >> I >> O >> T >> J >> L;
    ll ans1 = O, ans2 = O; //0じゃなくてO
    ans1 += I / 2 * 2 + J / 2 * 2 + L / 2 * 2;
    if (min({I, J, L}) > 0) {
        ans2 += 3;
        I--, J--, L--;
    }
    ans2 += I / 2 * 2 + J / 2 * 2 + L / 2 * 2;
    cout << max(ans1, ans2) << endl;
    return 0;
}

