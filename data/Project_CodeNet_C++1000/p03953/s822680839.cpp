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

int n, a[MX], m;
ll x[MX], cum[MX];
ll k;

void sim(int z) {
    x[z] = x[z-1]+x[z+1]-x[z];
}

void input() {
    // freopen("A.txt","r",stdin);
    // freopen("C.txt","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    FOR(i,1,n+1) cin >> x[i];
    cin >> m >> k;
    FOR(i,1,m+1) cin >> a[i];
}

void brute() {
    F0R(i,k) FOR(j,1,n+1) sim(a[j]);
    FOR(i,1,n+1) cout << x[i] << " ";
}

void ad(int l, int r, ll x) {
    cum[l] += x, cum[r+1] -= x;
}

int locLeft[60][MX], locRight[60][MX];

int getLocLeft(int x, ll y) {
    F0Rd(i,60) if (y&(1LL<<i)) x = locLeft[i][x];
    return x;
}

int getLocRight(int x, ll y) {
    F0Rd(i,60) if (y&(1LL<<i)) x = locRight[i][x];
    return x;
}

int tmpLeft[MX], tmpRight[MX];

int main() {
    input();
    FOR(i,1,n+1) tmpLeft[i] = tmpRight[i] = i;
    FOR(i,1,m+1) {
        swap(tmpRight[a[i]-1],tmpRight[a[i]]);
        swap(tmpLeft[a[i]+1],tmpLeft[a[i]]);
    }
    FOR(i,1,n+1) {
        locLeft[0][tmpLeft[i]] = i;
        locRight[0][tmpRight[i]] = i;
    }
    FOR(j,1,60) FOR(i,1,n+1) {
        locLeft[j][i] = locLeft[j-1][locLeft[j-1][i]];
        locRight[j][i] = locRight[j-1][locRight[j-1][i]];
    }
    FOR(i,1,n+1) {
        int a = getLocLeft(i,k), b = getLocRight(i,k);
        // cout << a << " " << b << "\n";
        if (a <= b) ad(a,b,x[i]);
        else ad(b+1,a-1,-x[i]);
    }
    
    FOR(i,1,n+1) {
        cum[i] += cum[i-1];
        cout << fixed << setprecision(1) << (ld)cum[i] << "\n";
    }
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS