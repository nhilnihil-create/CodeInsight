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
typedef pair<lint, lint> pil;
typedef complex<double> xy_t;

const lint mod = 1e9 + 7;

int main(){
    int n;
    scanf("%d", &n);
    lint a[n];
    rep(i, n) scanf("%lld", &a[i]);

    lint cur = 1, ans = 0;
    rep(i, n){
        if(a[i] == cur) ++cur;
        else if(a[i] > cur){
            ans += (a[i]-1) / cur;
            a[i] = (a[i]%cur) ? a[i]%cur : 1;
            if(a[i] == cur) ++cur;
        }
    }
    printf("%lld\n", ans);
}