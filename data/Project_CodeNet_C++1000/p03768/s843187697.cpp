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
const ld PI = 4*atan((ld)1);

int N,M,Q,dis[MX],col[MX];
vi adj[MX];
vector<array<int,3>> todo;

void process(int v, int d, int c) {
    if (d <= dis[v]) return;
    dis[v] = d;
    if (col[v] == 0) col[v] = c;
    for (int i: adj[v]) process(i,d-1,c);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    FOR(i,1,N+1) dis[i] = -1;
    F0R(i,M) {
        int a,b; cin >> a >> b;
        adj[a].pb(b), adj[b].pb(a);
    }
    int Q; cin >> Q;
    F0R(i,Q) {
        int v,d,c; cin >> v >> d >> c;
        todo.pb({v,d,c});
    }
    reverse(all(todo));
    for (auto a: todo) process(a[0],a[1],a[2]);
    FOR(i,1,N+1) cout << col[i] << "\n";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS