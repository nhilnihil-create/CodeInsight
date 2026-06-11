#include <bits/stdc++.h>
using namespace std;

vector<int> edges[2000];

int dfs(int i, int p, int lim, int d){
    int ans = (lim < d);
    for(int j : edges[i]) if(j != p) ans += dfs(j, i, lim, d+1);
    return ans;
}

int main(){
    int N, K;
    cin >> N >> K;
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }
    int ans = N;
    if(K%2){
        for(int i=0; i<N; i++) for(int j : edges[i]){
            ans = min(ans, dfs(i, j, K/2, 0) + dfs(j, i, K/2, 0));
        }
    }else{
        for(int i=0; i<N; i++) ans = min(ans, dfs(i, -1, K/2, 0));
    }
    cout << ans << endl;
}