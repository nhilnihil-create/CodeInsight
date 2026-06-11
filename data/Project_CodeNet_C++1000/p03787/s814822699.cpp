#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int n;
int m;
const int maxn = 1e5 + 5;
vector<int> G[maxn];

int c[maxn];

bool flag;

int dfs(int u, int col){
    c[u] = col;
    int ans = 1;
    for(auto v : G[u]){
        if(c[v] == -1){
            ans += dfs(v, col ^ 1);
        }else{
            if(c[v] == col)
                flag = false;
        }
    } 
    return ans;
}

int cnt[3];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(c, -1, sizeof(c));
    for(int i = 1;i <= n;i++){
        if(c[i] == -1){
            flag = true;
            int sz = dfs(i, 1);
            if(sz == 1)
                cnt[0]++;
            else{
                if(flag){
                    cnt[1]++;
                }else{
                    cnt[2]++;
                }
            }
        } 
    }
    ll ans = 0;
    ans += 2LL * cnt[1] * cnt[1];
    ans += 1LL * cnt[2] * cnt[2];
    ans += 2LL * cnt[1] * cnt[2];
    ans += 1LL * cnt[0] * (2 * n - cnt[0]);
    cout << ans << endl;
    return 0;
}
