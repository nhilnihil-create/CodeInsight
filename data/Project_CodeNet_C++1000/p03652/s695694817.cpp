#include<bits/stdc++.h>
using namespace std;

#define LL long long
int n, m, a[305][305], vis[305];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];

    int ans = 1e9; memset(vis, 1, sizeof vis);

    for(int k = 1; k <= m; k++) {
        int res = 0, cnt[m+1]={}, id = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int x = a[i][j];
                if(vis[x]) {
                    cnt[x]++;
                    if(res < cnt[x]) {
                        res = cnt[x], id = x;
                    }
                    break;
                }
            }   
        }
        vis[id] = 0;
        ans = min(ans, res);
    }        
    cout << (m == 1 ? n : ans);
}