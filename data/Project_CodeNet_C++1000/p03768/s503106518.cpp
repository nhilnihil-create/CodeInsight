#include<iostream>
#include<vector>
using namespace std;

int N, M, Q;
vector<int> adj[100000];
int dp[100000][11];
int c_arr[100000];

void go(int now, int d, int q_cnt){
    for(int i = 0; i < d; i++){
        dp[now][i] = max(dp[now][i], q_cnt);
    }
    if(d == 0){
        return;
    }
    for(int i = 0; i < adj[now].size(); i++){
        int next = adj[now][i];
        dp[next][d-1] = max(dp[next][d-1], q_cnt);
        go(next, d-1, q_cnt);
    }
}

void visit(int now){
    int m = -1;
    for(int d = 10; d >= 0; d--){
        if(dp[now][d] > m){
            go(now, d, dp[now][d]);
            m = dp[now][d];
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= 10; j++){
            dp[i][j] = -1;
        }
    }
    cin >> Q;
    for(int i = 0; i < Q; i++){
        int v, d, c;
        cin >> v >> d >> c;
        v--;
        c_arr[i] = c;
        dp[v][d] = max(dp[v][d], i);
    }

    for(int d = 10; d > 0; d--){
        for(int i = 0; i < N; i++){
            dp[i][d-1] = max(dp[i][d-1], dp[i][d]);
            for(int j = 0; j < adj[i].size(); j++){
                int next = adj[i][j];
                dp[next][d-1] = max(dp[next][d-1], dp[i][d]);
            }
        }
    }

    

    for(int i = 0; i < N; i++){
        if(dp[i][0] == -1){
            cout << 0 << endl;
        }else{
            cout << c_arr[dp[i][0]] << endl;
        }
    }
}
    
