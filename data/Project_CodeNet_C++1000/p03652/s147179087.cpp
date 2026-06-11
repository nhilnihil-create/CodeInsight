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
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n][m], b[m][n];
    rep(i, n)rep(j, m){
        scanf("%d", &a[i][j]);
        --a[i][j];
        b[a[i][j]][i] = j;
    }
    set<pii> s[n];
    rep(i, n)rep(j, m) s[i].insert(pii(j, a[i][j]));

    int num[m], tmp = 0, ans;
    rep(i, m) num[i] = 0;
    rep(i, n) ++num[a[i][0]];
    rep(i, m) tmp = max(tmp, num[i]);
    ans = tmp;

    rep(i, m-1){
        rep(j, m)if(num[j] == tmp){
            rep(k, m) num[k] = 0;
            rep(k, n){
                s[k].erase(pii(b[j][k], j));
                ++num[(*(s[k].begin())).se];
            }
            tmp = 0;
            rep(k, m) tmp = max(tmp, num[k]);
            ans = min(ans, tmp);
            break;
        }
    }

    printf("%d\n", ans);
}