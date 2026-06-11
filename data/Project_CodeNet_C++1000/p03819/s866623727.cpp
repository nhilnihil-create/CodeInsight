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

const int MAXN = 1<<17;
int N = 1<<17;
struct Node { 
	ll val;
} SEG[10000000];

int e = 0;
int LFT[10000000], RGT[10000000];

int roots[MAXN];
    
int build(int l = 0, int r = N - 1) {
	//build from L to R inclusive. 
	int x = ++e;
	if (l == r){
		SEG[x].val = 0;
		LFT[x] = -1;
		RGT[x] = -1;
		return x;
	}
	int mid = (l + r)/2;
	LFT[x] = build(l, mid);
	RGT[x] = build(mid + 1, r);
	return x;
}

int upd(int cur, int pos, int set, int l = 0, int r = N - 1) {
	//set a[pos] = set in the root cur
	if (r < pos || pos < l) return cur;
	int x = ++e;
	//we're creating a new node
	if (l == r){
		SEG[x].val = SEG[cur].val+set;
		return x;
	}
	int m = (l+r)/2;
	LFT[x] = upd(LFT[cur], pos, set, l, m);
	RGT[x] = upd(RGT[cur], pos, set, m + 1, r);
	SEG[x].val = SEG[LFT[x]].val + SEG[RGT[x]].val;
	return x;
}

ll query(int cur, int L, int R, int l = 0, int r = N - 1){
	if (r < L || R < l) return 0LL;
	int m = (l + r)/2;
	if (L <= l && r <= R) return SEG[cur].val;
	return query(LFT[cur], L, R, l, m) + query(RGT[cur], L, R, m + 1, r);
}


int n,M;
vi todo[MX];

void solve(int x) {
    int ans = 0;
    for (int i = x; i <= M; i += x) {
        ans += query(roots[i-x+1],0,i);
        //cout << "AH " << i-x+1 << " " << i << " " << p.query(i-x+1,0,i) << "\n";
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> M;
    F0R(i,n) {
        int a,b; cin >> a >> b;
        todo[a].pb(b);
    }
    vi emp;
    roots[M+1] = build();
    FORd(i,1,M+1) {
        roots[i] = roots[i+1];
        roots[i] = upd(roots[i],i,sz(todo[i]));
        for (int j: todo[i]) {
            //cout << "HI " << i << " " << j << "\n";
            //cout << "AA " << i << " " << query(roots[i],0,N-1) << " " << N << "\n";
            roots[i] = upd(roots[i],j+1,-1);
            //cout << "BB " << query(roots[i],0,N-1) << "\n";
        }
    }
    
    FOR(i,1,M+1) solve(i);
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS