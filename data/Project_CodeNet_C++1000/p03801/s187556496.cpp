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
typedef pair<lint, lint> pll;

int main(){
    int n;
    scanf("%d", &n);
    pll a[n+1];
    rep(i, n){
        lint t;
        scanf("%lld", &t);
        a[i] = make_pair(t, i);
    }
    a[n] = make_pair(0, -1);
    sort(a, a+n+1, greater<pll>());
    lint ans[n];
    rep(i, n) ans[i] = 0;
    lint cur = 1e7;
    rep(i, n){
        cur = min(cur, a[i].se);
        if(a[i].fi != a[i+1].fi){
            ans[cur] += (lint)(a[i].fi - a[i+1].fi) * (i+1);
        }
    }
    rep(i, n) printf("%lld\n", ans[i]);
}
