#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001;

int H,W,N;
set<pi> tri,z;
ll ans[10];

bool valid(pi x) {
    return 1 <= x.f && x.f <= H-2 && 1 <= x.s && x.s <= W-2;
}

int co(pi a) {
    int ans = 0;
    F0R(i,3) F0R(j,3) if (z.count({a.f+i,a.s+j})) ans ++;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> H >> W >> N;
    F0R(i,N) {
        int a,b; cin >> a >> b;
        F0R(j,3) F0R(k,3) tri.insert({a-j,b-k});
        z.insert({a,b});
    }
    for (auto a: tri) if (valid(a)) ans[co(a)] ++;
    ll tot = (ll)(H-2)*(W-2);
    FOR(i,1,10) tot -= ans[i];
    ans[0] = tot;
    F0R(i,10) cout << ans[i] << "\n";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS