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

int N,M;
vi v[MX];
int ans = 0;
map<int,int> tmp[2];
set<int> odd[2];

void rem(int ind, int x) {
    if (odd[ind].count(x)) odd[ind].erase(x);
    tmp[ind][x] --;
    if (tmp[ind][x] == 0) {
        tmp[ind].erase(x);
        return;
    }
    if (tmp[ind][x]&1) odd[ind].insert(x);
}

void solve(int x) {
    if (x == 0 || x == M-x) {
        ans += sz(v[x])/2;
        // cout << "HUH " << x << "\n";
    } else {
        F0R(k,2) tmp[k].clear(), odd[k].clear();
        for (auto a: v[x]) tmp[0][a] ++;
        for (auto a: v[M-x]) tmp[1][a] ++;
        F0R(k,2) for (auto& a: tmp[k]) if (a.s&1) odd[k].insert(a.f);
        
        while (sz(odd[0]) || sz(odd[1])) {
            if (sz(odd[0]) && sz(odd[1])) {
                rem(0,*odd[0].begin());
                rem(1,*odd[1].begin());
                ans ++;
            } else if (sz(odd[0])) {
                if (sz(tmp[1])) {
                    rem(0,*odd[0].begin());
                    rem(1,tmp[1].begin()->f);
                    ans ++;
                } else break;
            } else {
                if (sz(tmp[0])) {
                    rem(1,*odd[1].begin());
                    rem(0,tmp[0].begin()->f);
                    ans ++;
                } else break;
            }
        }
        
        F0R(k,2) for (auto& a: tmp[k]) ans += a.s/2;
        /*cout << "HI\n";
        for (int i: v[x]) cout << i << " ";
        cout << "\n---\n";
        for (int i: v[M-x]) cout << i << " ";
        cout << "\n---\n";*/
    }
    // cout << "OH " << x << " " << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    F0R(i,N) {
        int x; cin >> x;
        v[x%M].pb(x);
    }
    for (int i = 0; i <= M-i; ++i) solve(i);
    cout << ans;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS