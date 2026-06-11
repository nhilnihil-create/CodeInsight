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

int N,M,odd,A[MX];
vi B;

void ad(int x) {
    if (x) B.pb(x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    F0R(i,M) {
        cin >> A[i];
        if (A[i]&1) odd ++;
    }
    if (N == 1) {
        cout << A[0] << "\n" << 1 << "\n" << A[0];
        exit(0);
    }
    if (M == 1) {
        cout << A[0] << "\n" << 2 << "\n" << A[0]-1 << " 1\n";
        exit(0);
    }
    F0R(i,M) if (A[i]&1) {
        swap(A[i],A[0]);
        break;
    }
    FOR(i,1,M) if (A[i]&1) {
        swap(A[i],A[M-1]);
        break;
    }
    if (N % 2 == 0) {
        if (odd > 2) {
            cout << "Impossible";
            exit(0);
        } 
    } else {
        if (odd > 1) {
            cout << "Impossible";
            exit(0);
        }
    }
    F0R(i,M) cout << A[i] << " ";
    cout << "\n";
    F0R(i,M) {
        if (i == 0) ad(A[i]+1);
        else if (i == M-1) ad(A[i]-1);
        else ad(A[i]);
    }
    cout << sz(B) << "\n";
    for (int i: B) cout << i << " ";
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS