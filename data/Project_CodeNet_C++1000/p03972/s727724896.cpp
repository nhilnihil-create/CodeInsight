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

int main(){
    lint w, h;
    scanf("%lld%lld", &w, &h);
    lint sum = 0;
    lint a[w], b[h];
    rep(i, w){
        scanf("%lld", &a[i]);
        sum += a[i] * (h+1);
    }
    rep(i, h){
        scanf("%lld", &b[i]);
        sum += b[i] * (w+1);
    }
    sort(a, a+w);
    sort(b, b+h);
    rep(i, w) sum -= a[i] * (upper_bound(b, b+h, a[i]) - b);
    rep(i, h) sum -= b[i] * (lower_bound(a, a+w, b[i]) - a);
    printf("%lld", sum);
}