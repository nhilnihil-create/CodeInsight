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
#define outs(x) cout << (x) << " "
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

int main(){
    ii2(n, x); n = 2*n-1;
    if(x == n || x == 1){
        out("No"); return 0;
    }

    out("Yes");
    if(n == 3 && x == 2){
        out(1); out(2); out(3); return 0;
    }

    vector<int> a, b, c;
    int l = (n-4)/2; int r = l+1;
    if(x == 2){
        b.push_back(4); b.push_back(1);
        b.push_back(2); b.push_back(3);
        int k = 5;
        rep(i, l){
            a.push_back(k); k++;
        }
        rep(i, r){
            c.push_back(k); k++;
        }
    }
    else{
        b.push_back(x-1); b.push_back(x);
        b.push_back(x+1); b.push_back(1);
        int k = 2;
        rep(i, l){
            if(k == x-1) k = x+2;
            a.push_back(k); k++;
        }
        rep(i, r){
            if(k == x-1) k = x+2;
            c.push_back(k); k++;
        }
    }

    rep(i, l) out(a[i]);
    rep(i, 4) out(b[i]);
    rep(i, r) out(c[i]);
}
