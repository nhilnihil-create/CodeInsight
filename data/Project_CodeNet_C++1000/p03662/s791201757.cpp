#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, INF = 100001;
int dist1[100000], dist2[100000];
int check[100000];
vector<int> G[100000];

void bfs(int s, int d[]){
    queue<int> q;
    
    for(int i=0;i<100000;i++) check[i] = 0;
    check[s] = 1;
    q.push(s);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=0;i<G[u].size();i++){
            int v = G[u][i];
            if(check[v]==0){
                check[v] = 1;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    int a, b;
    cin >> N;

    for(int i=0;i<N-1;i++){
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }

    bfs(0, dist1);
    bfs(N-1, dist2);

    int cnt_f = 0;
    for(int i=0;i<N;i++)
        if(dist1[i] <= dist2[i]) cnt_f++;

    if(N/2 < cnt_f) cout << "Fennec" << endl;
    else cout << "Snuke" << endl;

    return 0;
}
