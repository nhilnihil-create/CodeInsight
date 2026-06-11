#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
using namespace std;
typedef long long lint;

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    int a[n]; lint b[n];
    rep(i, n) scanf("%d%lld", &a[i], &b[i]);
    lint ans = 0;
    rep(i, n)if((k | a[i]) == k) ans += b[i];
    rep(i, 31)if((k>>i)&1){
        lint tmp = 0;
        rep(j, n)if(((k>>(i+1)) | (a[j]>>(i+1))) == (k>>(i+1)) && !((a[j]>>i)&1)){
            tmp += b[j];
        }
        ans = max(ans, tmp);
    }
    printf("%lld\n", ans);
}