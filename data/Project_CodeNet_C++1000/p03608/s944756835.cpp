#include <bits/stdc++.h>

#define INF 1e9
using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,r;
    cin >> n >> m >> r;
    vector<int> s(r);
    for(int i = 0; i < r; i++) {
        cin >> s[i];
    }

    int wf[n][n];
    for(int i = 0; i < n*n; i++) {
        wf[i/n][i%n]=INF;
    }
    for(int i = 0; i < m; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        --a;
        --b;
        wf[a][b]=c;
        wf[b][a]=c;
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                wf[i][j] = min(wf[i][j], wf[i][k] + wf[k][j]);
            }
        }
    }

    vector<int> vis(r);
    for(int i = 0; i < r; i++) {
        vis[i]=i;
    }

    int ans=INT32_MAX;
    while(next_permutation(vis.begin(),vis.end())) {
        int tans=0;
        for(int i = 1; i < r; i++) {
            tans+=wf[s[vis[i-1]]-1][s[vis[i]]-1];
        }
        ans=min(tans,ans);
    }
    cout << ans << "\n";
    return 0;
}