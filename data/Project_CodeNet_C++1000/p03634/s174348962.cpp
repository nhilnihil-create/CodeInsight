#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,q,K;
    cin >> N;
    vector<long long int> len(N,-1);
    vector<vector<pair<long long int,long long int>>> graph(N);
    queue<long long int> Q;


    for(int i=0;i<N-1;i++){
        long long int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    cin >> q >> K;
    K--;

    len[K] = 0;
    Q.push(K);

    while(!Q.empty()){
        long long int now = Q.front();
        Q.pop();
        for(int i=0;i<graph[now].size();i++){
            if(len[graph[now][i].first]== -1){
                len[graph[now][i].first] = len[now]+graph[now][i].second;
                Q.push(graph[now][i].first);
            }
        }
    }

    for(int i=0;i<q;i++){
        long long int x,y;
        cin >> x >> y;
        x--;
        y--;
        cout << len[x]+len[y] << endl;
    }
}