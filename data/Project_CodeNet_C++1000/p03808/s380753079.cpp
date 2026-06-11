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
vi a;
vi nst;

signed main(){
    I(n);
    a.resize(n);
    REP(i,n) I(a[i]);
    int suma = accumulate(all(a), 0LL);
    int mini = *min_element(all(a));
    int maxi = *max_element(all(a));
    int once = (n+1) * n / 2;
    int nop = suma / once;
    if (suma % once != 0 || mini < nop || maxi > nop * n ){
        cerr << "input kill" << endl;
        cout << "NO" << endl;
        return 0;
    }
    nst.resize(n);
    // 差は 1 か 1-n か
    // a_i+1 - a_i = x + (1-n)(o-x)
    //             = o - no + nx

    REP(i,n){
        int neigh = (i+1) % n;
        int nx = (a[neigh] - a[i]) - (nop - nop * n);
        if (nx % n != 0 || nx/n < 0 || nx/n > nop){
            cerr << neigh << " NG" << endl;
            cout << "NO" << endl;
            return 0;
        }
        nst[neigh] = nx/n;
    }
    
    cout << "YES" << endl;
    return 0;
}