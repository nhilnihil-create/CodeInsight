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

int N,A[MX],ori[MX];
set<int> adj[MX];
vl num[MX];

void finish(int x) {
    sort(all(num[x]));
    ll mx = 0; for (int i: num[x]) mx += i;
    if (2*num[x].back() > mx || 2*A[x] != mx) cout << "NO";
    else cout << "YES";
    exit(0);
}

queue<int> todo;

void process(int x) {
    int par = *adj[x].begin();
    
    // cout << "AH " << x << "\n";
    if (!ori[x]) {
        sort(all(num[x]));
        ll mx = 0; for (int i: num[x]) mx += i;
        ll posi = min(mx/2,mx-num[x].back());
        
        ll need = mx-A[x];
        if (need < 0 || need > posi) {
            cout << "NO";
            exit(0);
        }
        
        A[x] -= need;
    }
    
    adj[par].erase(x), adj[x].erase(par);
    num[par].pb(A[x]);
    if (sz(adj[par]) == 1) {
        // cout << x << " " << par << "\n";
        todo.push(par);
    } else if (sz(adj[par]) == 0) finish(par);
    
    // cout << "ZZ " << x << " " << par << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    FOR(i,1,N+1) cin >> A[i];
    if (N == 2) {
        if (A[1] == A[2]) cout << "YES";
        else cout << "NO";
        exit(0);
    }
    F0R(i,N-1) {
        int a,b; cin >> a >> b;
        adj[a].insert(b), adj[b].insert(a);
    }
    FOR(i,1,N+1) if (sz(adj[i]) == 1) {
        ori[i] = 1;
        todo.push(i);
    }
    while (sz(todo)) {
        int x = todo.front(); todo.pop();
        process(x);
    }
    cout << "YES";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS