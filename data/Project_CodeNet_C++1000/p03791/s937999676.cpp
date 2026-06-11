#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef pair<int, int> pii;
typedef complex<double> xy_t;

const lint mod = 1e9 + 7;

int main(){
    int n;
    scanf("%d", &n);
    lint x[n];
    rep(i, n) scanf("%d", &x[i]);
    
    lint ans = 1;
    int d, cnt;
    cnt = 0;
    rep(i, n){
        d = x[i];
        ++cnt;
        if(d < 2*cnt-1) (ans *= (cnt--)) %= mod;
    }
    
    rep(i, cnt) (ans *= 1LL * (i+1)) %= mod;
    
    printf("%lld\n", ans);
}