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
const int MX = 100005;

int n, m;
ll cum[MX], cumX[MX], a[MX];

void ad(int l, int r, int x) {
    cum[l] += x, cum[r+1] -= x;
}

void adX(int l, int r, int x) {
    cumX[l] += x, cumX[r+1] -= x;
}

void process(int ind) {
    if (a[ind] <= a[ind+1]) {
        int dif = a[ind+1]-a[ind];
        ad(1,a[ind],dif); ad(a[ind+1]+1,m,dif);
        ad(a[ind]+1,a[ind+1],a[ind+1]+1), adX(a[ind]+1,a[ind+1],-1);
    } else {
        int dif = a[ind+1]-a[ind]+m;
        ad(a[ind+1]+1,a[ind],dif);
        ad(a[ind]+1,m,m+a[ind+1]+1), adX(a[ind]+1,m,-1);
        ad(1,a[ind+1],a[ind+1]+1), adX(1,a[ind+1],-1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    F0R(i,n) cin >> a[i];
    F0R(i,n-1) process(i);
    ll ans = INF;
    FOR(i,1,m+1) {
        cum[i] += cum[i-1];
        cumX[i] += cumX[i-1];
        // cout << "HI " << cumX[i]*i+cum[i] << "\n";
        ans = min(ans,cumX[i]*i+cum[i]);
    }
    cout << ans;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS