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

int main(){
    ii(n); lint W, w0, v0; cin >> W >> w0 >> v0;
    vector<lint> vec[4]; vec[0].push_back(v0);
    rep(i, n-1){
        lint w, v; cin >> w >> v;
        vec[w - w0].push_back(v);
    }
    
    int vs[4];
    rep(i, 4){
        vs[i] = vec[i].size();
        sort(all(vec[i]), greater<lint>());
        rep(j, vs[i]-1) vec[i][j+1] += vec[i][j];
        vec[i].insert(vec[i].begin(), 0);
    }

    lint ans = 0;
    rep(i, vs[0]+1) rep(j, vs[1]+1) rep(k, vs[2]+1) rep(l, vs[3]+1){
        lint ww = (i+j+k+l)*w0 + j + 2*k + 3*l;
        if(ww <= W){
            lint vv = vec[0][i] + vec[1][j] + vec[2][k] + vec[3][l];
            ans = max(ans, vv);
        }
    }
    out(ans);
}