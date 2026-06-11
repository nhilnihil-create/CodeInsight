#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    int N,M;
    cin>>N>>M;
    ll INF = 1e14;
    vector<vector<ll>> graph(N,vector<ll>(N,INF));
    vector<vector<ll>> prev(N,vector<ll>(N,INF));
    for(int i=0;i<M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        graph[a][b] = graph[b][a] = c;
        prev[a][b] = i;
        prev[b][a] = i;
    }

    for(int k = 0;k < N;k++){
        for(int i = 0;i < N;i++){
            for(int j = 0;j < N;j++){
                if(graph[i][j]>graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                    prev[i][j] = prev[k][j];
                }
                
            }
        }
    }
    // for(int i = 0;i < N;i++){
    //     for(int j = 0;j < N;j++){
    //         cout << graph[i][j] << " ";
    //     }
    //     cout<<endl;
    // }
    vector<bool> used(M,false);
    int cnt = M;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(prev[i][j] == INF || used[prev[i][j]])continue;
            used[prev[i][j]] = true;
            cnt--;
        }
    }
    cout<<cnt<<endl;
}