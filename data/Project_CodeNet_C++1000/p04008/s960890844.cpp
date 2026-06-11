#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 1e5 + 5;
int n;
int a[maxn];
int k;
int ans;
int fa[maxn];

vector<int> G[maxn], rG[maxn];

int dfs(int u, int f){
    fa[u] = f;
    int mx = 1;
    for(auto v : rG[u]){
        mx = max(mx, 1 + dfs(v, u));
    }
    if(mx >= k){
        mx = 0;
        if(fa[u] != 1)
            ans++;
    }
    return mx;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    ans = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(i == 1){
            if(a[i] != 1){
                ans++;
            }
        }else{
            G[i].push_back(a[i]);
            rG[a[i]].push_back(i);
        }
    }
    dfs(1, 1);
    cout << ans << endl;
    return 0;
}
