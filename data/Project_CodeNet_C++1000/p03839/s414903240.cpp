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

int n,k;
vi a;

int loss(int p, int n){
    return p < -n ? p : -n;
}
signed main(){
    I(n); I(k);
    a.resize(n+1);
    REP(i,n) I(a[i]);

    int mask = 1e+15;
    int maskl = -1;
    int maskblack = 0;
    int shakup = 0;
    int shakun = 0;
    
    REP(i,k) (a[i] > 0 ? shakup : shakun) += a[i];
    REP(i,n-k){
        if(mask > loss(shakup, shakun)){
            mask = loss(shakup, shakun);
            maskl = i;
            maskblack = (shakup + shakun >= 0);
        }
        (a[i] > 0 ? shakup : shakun) -= a[i];
        (a[i+k] > 0 ? shakup : shakun) += a[i+k];
        
    // cerr << loss(shakup, shakun) << endl;
    }
        if(mask > loss(shakup, shakun)){
            mask = loss(shakup, shakun);
            maskl = n-k;
            maskblack = (shakup + shakun >= 0);
            
        }
    int ret = 0;
    REP(i,n){
        if (maskl <= i && i < maskl + k){
            ret += a[i] * maskblack;
        } else {
            ret += max(0LL,a[i]);
        }
    }
    cout << ret << endl;
    

    
}