#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn = 111;
LL w[maxn], v[maxn], w0;
int N, W;
LL ans;
vector<LL> vv[5];
LL pre[5][maxn];
bool cmp (LL a, LL b) {
    return a > b;
}
int main () {
    scanf ("%d%d", &N, &W);
    for (int i = 0; i < N; i++) {
        scanf ("%d%d", &w[i], &v[i]);
    }
    w0 = w[0];
    for (int i = 0; i < N; i++) {
        vv[w[i]-w0].push_back (v[i]);
    }
    for (int i = 0; i < 4; i++) {
        sort (vv[i].begin(), vv[i].end(), cmp);
        for (int j = 0; j < vv[i].size(); j++) {
            pre[i][j+1] = pre[i][j] + vv[i][j];
        }
    }
    for (int i = 0; i <= vv[0].size(); i++) {
        for (int j = 0; j <= vv[1].size(); j++) {
            for (int k = 0; k <= vv[2].size(); k++) {
                for (int l = 0; l <= vv[3].size(); l++) {
                    if (w0*i+(w0+1)*j+(w0+2)*k+(w0+3)*l <= W) {
                        ans = max (ans, pre[0][i]+pre[1][j]+pre[2][k]+pre[3][l]);
                    }
                }
            }
        }
    }
    printf ("%lld", ans);
}
