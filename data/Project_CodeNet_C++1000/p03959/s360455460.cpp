//----------------------------templates
    #pragma GCC optimize ("Ofast")
    #pragma GCC target ("tune=native")
    #pragma GCC target ("avx")
    //----------------------------
    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef unsigned long long ull;
    #define int ll

    #define FOR(i,j,n) for (int i=(int)(j);i<(n);i++)
    #define REP(i,n) for (int i=0;i<(int)(n);i++)
    #define REPS(i,n) for (int i=1;i<=(int)(n);i++)
    #define REPN(i,n) for (int i=(int)(n)-1;i>=0;i--)
    #define REPNS(i,n) for (int i=(int)(n);i>0;i--)

    #define I(n) scanf("%lld", &(n))
    #define LL(n) scanf("%lld", &(n))
    #define pb(n) push_back((n))
    #define mp(i,j) make_pair((i),(j))
    #define eb(i,j) emplace_back((i),(j))
    #define y0 y3487465
    #define y1 y8687969
    #define j0 j1347829
    #define j1 j234892
    #define uniq(v) v.erase( unique(v.begin(), v.end()), v.end() )

    #define all(x) (x).begin(),(x).end()
    #define sz(x) ((int)(x).size())

    typedef vector<int> vi;
    typedef pair<int,int> pi;
    typedef vector<pi> vpi;
    typedef vector<vi> vvi;
    typedef vector<vpi> vvpi;
    typedef vector<vvi> vvvi;

    const int mod = 1000000007;

//--------------------------------------------

int n;
vi t,a,det;
int ret;

signed main(){
    I(n);
    t.resize(n);
    a.resize(n);
    REP(i,n) I(t[i]);
    REP(i,n) I(a[i]);

    det.resize(n);
    det[0] = t[0];
    FOR(i,1,n){
        if (t[i] != t[i-1]) det[i] = t[i];
    }
    if ( (det[n-1] != 0 && det[n-1] != a[n-1]) || t[n-1] < a[n-1]){
        cout << 0 << endl;
        return 0;
    }
    det[n-1] = a[n-1];
    REPN(i,n-1){
        if (a[i] != a[i+1]){
            if (det[i] != 0 && det[i] != a[i]){
                cout << 0 << endl;
                return 0;
            }
            det[i] = a[i];
        }
        if (det[i] > a[i]) {
            cout << 0 << endl;
            return 0;
        }
    }
    ret = 1;
    REP(i,n){
        if(!det[i]){
            ret *= min(a[i],t[i]);
            ret %= mod;
        }
        // cerr << det[i] << " " << t[i] << " " << a[i] << endl;
    }
    cout << ret << endl;
}