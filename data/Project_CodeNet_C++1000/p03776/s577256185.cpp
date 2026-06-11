#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define fi first
#define se second
#define setpre(x) cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ cout << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , ";
    logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 100005;

/* ...o(^-^)o... */

const int MAX_C = 100;
lint cmb[MAX_C][MAX_C];
void cmb_init(){
    cmb[0][0] = 1;
    repn(i, 50) rep(j, i+1){
        if(j == 0) cmb[i][0] = 1;
        else if(j == i) cmb[i][i] = 1;
        else cmb[i][j] = cmb[i-1][j-1] + cmb[i-1][j];
    }
}

int main(){
    cmb_init();

    ii3(n,a,b);
    vector<lint> vec;
    rep(i, n){
        lint x; cin >> x; vec.push_back(x);
    }
    sort(all(vec), greater<lint>());

    bool flag = true;
    double avg = 0;
    rep(i, a){
        if(vec[i] != vec[0]){ flag = false; }
        avg += vec[i];
    }
    setpre(6); out(avg / a);

    if(flag){
        int k = 0;
        for(int i = a; i < n; i++){
            if(vec[i] != vec[0]) break;
            k++;
        }
        lint ans = 0;
        for(int i = 0; (i <= k && a+i <= b); i++){
            ans += cmb[a+k][a+i];
        }
        out(ans); return 0;
    }

    int m = 0, l = 0;
    rep(i, n){
        if(vec[i] == vec[a-1]){
            if(i < a-1) m++;
            else if(i > a-1) l++;
        }
    }
    lint ans = cmb[m+l+1][m+1];
    out(ans);
}