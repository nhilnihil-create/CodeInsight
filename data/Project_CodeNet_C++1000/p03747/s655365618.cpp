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

vi v;
int N,L,T;
ll desTot;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> L >> T;
    F0R(i,N) {
        int X,W; cin >> X >> W;
        if (W == 2) W = -1;
        v.pb(((X+T*W)%L+L)%L);
        desTot += X+T*W;
    }
    sort(all(v));
    ll z = 0; for (ll x: v) z += x;
    ll res = (((desTot-z)/L % N) + N) % N;
    
    vl v1 = vl(v.begin(),v.begin()+res);
    vl v2 = vl(v.begin()+res,v.end());
    for (auto a: v1) v2.pb(a+L);
    for (auto a: v2) cout << (a%L+L)%L << "\n";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS