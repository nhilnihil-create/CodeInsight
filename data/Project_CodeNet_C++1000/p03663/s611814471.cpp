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

int digl, digr, l, r;

int n(int d){
    int r = 1;
    REP(i,d) r *= 10;
    return r;
}
string ins;
bool check(){
    cin >> ins;
    return ins[0] == 'Y';
}
void ask(int i){
    cout << "? " << i << endl;
}
void decide(int i){
    cout << "! " << i << endl;
}

signed main(){
    digr = 10;

    ask(n(10));
    if (check()){ // 10^n
        while(digr - digl > 1){
            int mid = (digr+digl)/2;
            ask(9 * n(mid-1));
            if( !check()) {
                digl = mid;
            } else {
                digr = mid;
            }
        }
        decide(n(digl));
    } else { // それ以外
        // 桁
        digr--; //10^9 はない
        while(digr - digl > 1){
            int mid = (digr+digl)/2;
            ask(n(mid));
            if( check()) {
                digl = mid;
            } else {
                digr = mid;
            }
        }
        l = n(digl);
        r = n(digl+1);
        while(r-l > 1){
            int mid = (l+r)/2;
            ask((mid-1)*10);
            if(check()){
                r = mid;
            } else {
                l = mid;
            }
        }
        decide(l);
    }
}