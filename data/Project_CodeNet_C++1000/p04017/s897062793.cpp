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
    int n;
    scanf("%d", &n);
    int x[n];
    rep(i, n) scanf("%d", &x[i]);
    int l;
    scanf("%d", &l);
    int lim[n][30];
    rep(i, n) lim[i][0] = lower_bound(x, x+n, x[i]+l+1) - x-1;
    rep(j, 29)rep(i, n) lim[i][j+1] = lim[lim[i][j]][j];
    int q;
    scanf("%d", &q);
    while(q--){
        int a, b;
        scanf("%d%d", &a, &b);
        --a; --b;
        if(a > b) swap(a, b);
        int ans = 0;
        rrep(i, 30)if(lim[a][i] < b){
            ans += 1 << i;
            a = lim[a][i];
        }
        printf("%d\n", ans + 1);
    }
}