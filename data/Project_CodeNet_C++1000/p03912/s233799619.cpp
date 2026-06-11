#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); ++(i))
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); --(i))
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
#define fi first
#define se second
using namespace std;
typedef long long lint;
typedef unsigned long long ulint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef complex<double> xy_t;
typedef vector<lint> poly;

const lint mod = 1e9 + 7;
const lint INF = mod * mod;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int x[n], cntx[100010];
    rep(i, 100010) cntx[i] = 0;
    rep(i, n){
        scanf("%d", &x[i]);
        ++cntx[x[i]];
    }

    int num[m][2];
    rep(i, m)rep(j, 2) num[i][j] = 0;
    rep(i, 100010)if(cntx[i]){
        int t = i % m;
        if(cntx[i] % 2) ++num[t][1];
        num[t][0] += cntx[i]/2*2;
    }

    int ans = 0;
    for(int i=0; i*2<=m; ++i) {
        if (i == 0 || i * 2 == m) {
            ans += (num[i][0] + num[i][1]) / 2;
            continue;
        }
        int s = i, t = m-s;
        int nums = num[s][0] + num[s][1], numt = num[t][0] + num[t][1];
        if(nums < numt) swap(s, t), swap(nums, numt);
        ans += numt;
        if(num[s][1] < numt){
            numt -= num[s][1];
            num[s][0] -= numt;
        }
        ans += num[s][0] / 2;
    }
    printf("%d\n", ans);
}
