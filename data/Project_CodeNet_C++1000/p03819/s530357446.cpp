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

template<int SZ> struct pseg {
    static const int LIMIT = 10000000;
    
    int val[LIMIT], l[LIMIT], r[LIMIT], nex = 0;
    
    int comb(int a, int b) { return a+b; }
    void pull(int x) { val[x] = comb(val[l[x]],val[r[x]]); }
    
    int query(int cur, int low, int high, int L, int R) {  
        if (low <= L && R <= high) return val[cur];
        if (R < low || high < L) return 0;
        int M = (L+R)/2;
        return comb(query(l[cur],low,high,L,M),query(r[cur],low,high,M+1,R));
    }
    
    int upd(int cur, int ind, int v, int L, int R) {
        if (R < ind || ind < L) return cur;
        int x = nex++;
        
        if (ind <= L && R <= ind) {
            val[x] = val[cur]+v;
            return x;
        }
        
        int M = (L+R)/2;
        l[x] = upd(l[cur],ind,v,L,M);
        r[x] = upd(r[cur],ind,v,M+1,R);
        pull(x);
        return x;
    }
    
    int build(vi& arr, int L, int R) {
        int cur = nex++;
        if (L == R) {
            if (L < sz(arr)) val[cur] = arr[L];
            return cur;
        }
        
        int M = (L+R)/2;
        l[cur] = build(arr,L,M), r[cur] = build(arr,M+1,R);
        pull(cur);
        
        return cur;
    }
    
    vi loc;
    void upd(int ind, int v) { loc.pb(upd(loc.back(),ind,v,0,SZ-1)); }
    int query(int ti, int low, int high) { return query(loc[ti],low,high,0,SZ-1); }
    void build(vi& arr) { loc.pb(build(arr,0,SZ-1)); }
};

pseg<1<<17> p;
int N,M;
vi todo[MX];
 
void solve(int x) {
    int ans = 0;
    for (int i = x; i <= M; i += x) {
        ans += p.query(i-x+1,0,i);
        // cout << "AH " << i-x+1 << " " << i << " " << p.query(i-x+1,0,i) << "\n";
    }
    cout << ans << "\n";
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    F0R(i,N) {
        int a,b; cin >> a >> b;
        todo[a].pb(b);
    }
    vi emp;
    p.loc.resize(M+2);
    p.loc[M+1] = p.build(emp,0,(1<<17)-1);
    FORd(i,1,M+1) {
        p.loc[i] = p.loc[i+1];
        p.loc[i] = p.upd(p.loc[i],i,sz(todo[i]),0,(1<<17)-1);
        for (int j: todo[i]) p.loc[i] = p.upd(p.loc[i],j+1,-1,0,(1<<17)-1);
    }
    
    FOR(i,1,M+1) solve(i);
}
 
// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS

/*
int tmp[101][8][8];

vi arr = {1,7,2,3,5,9,4,6};

int query(int l, int r) {
    int mn = -MOD;
    FOR(i,l,r+1) mn = max(mn,arr[i]);
    return mn;
}

void upd(int l, int r, int k) { FOR(i,l,r+1) arr[i] += k; }

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
	pseg<8> p = pseg<8>();
    p.build(arr);
    FOR(i,1,101) {
        int l = rand() % 8;
        int k = rand()%20-10;
        p.upd(l,k);
        upd(l,l,k);
        F0R(j1,8) FOR(j2,j1,8) tmp[i][j1][j2] = query(j1,j2);
        int z = rand() % i+1;
        F0R(j1,8) FOR(j2,j1,8) if(tmp[z][j1][j2] != p.query(z,j1,j2)) {
            cout << i << " " << z << " " << j1 << " " << j2 << "\n";
            cout << tmp[z][j1][j2] << " " << p.query(z,j1,j2) << "\n";
            exit(0);
        }
    }
}*/

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS