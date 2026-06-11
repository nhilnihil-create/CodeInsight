#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const int MX = 100005;

int w[2], a[2], t;
long long ans, p[2][MX];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> w[0] >> w[1];
    rep(i,2){
        rep(j,w[i]) cin >> p[i][j];
        p[i][w[i]] = 1e9;
        sort(p[i],p[i]+w[i]);
    }
    while(a[0] + a[1] < w[0] + w[1]){
        t = p[0][a[0]] > p[1][a[1]];
        ans += p[t][a[t]++] * (w[!t]+1 - a[!t]);
    }
    cout << ans << '\n';
}