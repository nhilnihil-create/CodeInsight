#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
#include <limits>
#include <algorithm>

int MOD_BIG = 1000000007;
int MOD_BIG2 = 998244353;
using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using ll = long long;
using pint = std::pair<int, int>;
using pll = std::pair<ll, ll>;
using std::vector;

#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

//////////////////////////////////////

struct Mod_nCm {
    ll MAX, MOD;
    vector<ll> fac, finv, inv;
    Mod_nCm(ll max, ll mod): MAX(max+1), MOD(mod), fac(MAX), finv(MAX), inv(MAX) {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < MAX; i++){
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }
    ll get_nCm(ll n, ll m) {
        if (n > MAX) return -1;
        if (n < m) return 0;
        if (n < 0 || m < 0) return 0;
        return fac[n] * (finv[m] * finv[n - m] % MOD) % MOD;
    }
};

//////////////////////////////////////

int main() {
    
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    int a = H - A;
    
    Mod_nCm ncm(H+W+1, MOD_BIG);
    
    ll sum = 0;
    
    FOR(b, 0, B) {
        sum += ncm.get_nCm(a+b-1, b) * ncm.get_nCm(W-b+A-2, A-1);
        sum %= MOD_BIG;
    }
    cerr << sum << endl;
    cerr << ncm.get_nCm(H+W-2, H-1) << endl;
    
    int ans = (ncm.get_nCm(H+W-2, H-1) - sum + MOD_BIG) % MOD_BIG;
    
    cout << ans << endl;
    
    return 0;
}