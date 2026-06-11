#include<bits/stdc++.h>
int n,m;
std::vector<std::vector<std::pair<int,int>>> hen; // ver : cost
std::vector<std::vector<int>> seen; //辺i-jの使用回数

void dijkstra(int start){
    std::vector<int> past(n, n + 5);
    std::vector<int> dist(n,1000000000);
    using T = std::pair<int, int>;
    std::priority_queue<T, std::vector<T>, std::greater<T>> que;
    que.push({0,start});
    dist[start] = 0;
    while(que.size()){
        auto cur = que.top();
        que.pop();
        for(auto i : hen[cur.second]){

            if(dist[cur.second] + i.second < dist[i.first]){
                dist[i.first] = cur.first + i.second;
                seen[i.first][past[i.first]]--;
                seen[past[i.first]][i.first]--;
                seen[i.first][cur.second]++;
                seen[cur.second][i.first]++;
                que.push({dist[i.first],i.first});
                past[i.first] = cur.second;
            }
        }
    }
}


int main()
{
    std::cin >> n >> m;
    hen.resize(n);
    seen.resize(n + 10,std::vector<int>(n + 10,-1000000000));
    for(int i = 0; i < m; i++){
        int a,b,c;
        std::cin >> a >> b >> c;
        a--; b--;
        hen[a].push_back({b,c});
        hen[b].push_back({a,c});
        seen[a][b] = 0;
        seen[b][a] = 0;
    }


    for(int i = 0; i < n; i++)dijkstra(i);
    int cnt = 0;


    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(seen[i][j] == 0)cnt++;
        }
    }

    std::cout << cnt << std::endl;

}
