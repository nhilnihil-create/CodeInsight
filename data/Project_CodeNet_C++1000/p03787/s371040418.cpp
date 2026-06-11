#include <iostream>
#include <vector>

using namespace std;

vector<int> G[100000];
int g[100000];
bool isBipartite;
int cnt;

void dfs(int v, int c){
    cnt++;
    g[v] = c;
    //cout << v << ' ' << c << endl;
    int col;
    if(c == 1) col = 2;
    else col = 1;
    for(int i = 0; i < G[v].size(); i++){
        if(g[G[v][i]] == 0)  dfs(G[v][i], col);
        else if(g[G[v][i]] != col) isBipartite = false;
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    long cnt_b = 0;
    long cnt_s = 0;
    long cnt_nb = 0;
    for(int i = 0; i < N; i++){
        isBipartite = true;
        cnt = 0;
        if(g[i] == 0){
            dfs(i, 1);
            //cout << i << ' ' << cnt << ' ' << isBipartite << endl;
            if(isBipartite && cnt != 1) cnt_b++;
            else if(cnt != 1)cnt_nb++;
            if(cnt == 1) cnt_s++;
        }
    }
    //cout << cnt_b << ' ' << cnt_nb << ' ' << cnt_s << endl;
    long ans = cnt_b*cnt_b*2+cnt_b*cnt_nb*2+cnt_nb*cnt_nb+2*cnt_s*N-cnt_s*cnt_s;
    cout << ans << endl;
}