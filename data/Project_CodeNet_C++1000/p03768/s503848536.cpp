#include <iostream>
#include <vector>

using namespace std;

bool dp[100000][11];
int col[100000];
vector<int> G[100000];

void dfs(int v, int d, int c){
    if(col[v] == 0) {
        col[v] = c;
    }
    for(int i = d; i >= 0; i--) dp[v][i] = true;
    if(d == 0){
        return;
    }
    for(int i = 0; i < G[v].size(); i++){
        if(!dp[G[v][i]][d-1]) dfs(G[v][i], d-1, c);
    }
}

int main(){
    int N, M ,Q;
    int v[100000];
    int d[100000];
    int c[100000];
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cin >> Q;
    for(int i = 0; i < Q; i++){
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }
    for(int i = Q-1; i >= 0; i--){
        if(!dp[v[i]][d[i]]){
            dfs(v[i], d[i], c[i]);
        }  
    }
    for(int i = 0; i < N; i++){
        cout << col[i] << endl;
    }
}