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

ll N;
map<ll,string> m;

ll comb(ll a, ll b) {
    ll ret = 1;
    F0R(i,b) {
        ret *= a-b+1+i;
        ret /= i+1;
    }
    return ret;
}

ll getLen(ll i) {
    return (ll)pow((ld)2,i-1)-1;
}

void solve(ll N) {
    int nex = 1;
    vi ans;
    while (N) {
        auto it = prev(m.ub(N));
        N -= it->f;
        for (char c: it->s) {
            if (c == 'a') ans.pb(nex);
            else ans.pb(nex+1);
        }
        // cout << N << " " << sz(ans) << "\n";
        nex += 2;
    }
    cout << sz(ans) << "\n";
    //if (sz(ans) > 200) {
        for (int i: ans) cout << i << " ";
        cout << "\n";
    //}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    FOR(a,1,14) FOR(b,1,14) FOR(c,1,14) FOR(d,1,14) {
        string s; 
        F0R(A,a) s += 'a';
        F0R(B,b) s += 'b';
        F0R(C,c) s += 'a';
        F0R(D,d) s += 'b';
        
        ll res = getLen(a+c)+getLen(b+d);
        FOR(i,1,min(a,c)+1) FOR(j,1,min(b,d)+1) res += comb(a,i)*comb(c,i)*comb(b,j)*comb(d,j);
        m[res] = s;
    }
    FOR(i,2,42) {
        string s; F0R(j,i) s += 'a';
        m[getLen(i)] = s;
        // cout << s << " " << (ll)pow((ld)2,i-1)-1 << "\n";
    }
    for (auto it = m.begin(); it != m.end(); ) {
        if (it != m.begin() && sz(prev(it)->s) < sz(it->s) && 0.99*it->f < prev(it)->f) {
            it = next(it);
            m.erase(prev(it));
        } else if (it != m.begin() && prev(it) != m.begin() && sz(prev(it)->s) > sz(it->s) && 0.99*it->f < prev(prev(it))->f) {
            m.erase(prev(it));
        } else {
            it = next(it);
        }
    }
    // for (auto& a: m) cout << a.f << " " << sz(a.s) << "\n";
    cin >> N; solve(N); 
    /*F0R(i,100) {
        solve(rand()+1000LL*rand());
    }*/
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS