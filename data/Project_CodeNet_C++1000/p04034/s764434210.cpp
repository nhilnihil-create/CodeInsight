#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int n, m;
const int maxn = 1e5 + 5;

bool vis[maxn];
int cnt[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cnt[i] = 1;
        vis[i] = 0;
    }
    vis[1] = 1;
    for(int i = 1;i <= m;i++){
        int u, v;
        cin >> u >> v;
        if(vis[u]){
            vis[v] = 1;
        }
        cnt[u]--;
        cnt[v]++;
        if(cnt[u] == 0){
            vis[u] = 0;
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(vis[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}
