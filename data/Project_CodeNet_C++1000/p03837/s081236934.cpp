#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = INT_MAX / 2;

int main() {
    using P = pair<int,int>;
    int N, M; cin >> N >> M;
    set<P> s;
    vector<vector<P>> G(N);
    vector<tuple<int, int, int>> w;
    vector<bool> check(M, false);
    for (int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        w.push_back(make_tuple(a, b, c));
        G[a].push_back(make_pair(c, b));
        G[b].push_back(make_pair(c, a));
    }
    
    for (int i = 0; i < N; i++)
    {
        vector<int> dist(N, INF);
        priority_queue<P, vector<P>, greater<P>> pos;
        pos.push(make_pair(0,i));
        dist[i] = 0;
        
        while(!pos.empty()){
            auto from = pos.top(); pos.pop();
            if(dist[from.second] < from.first) continue;
            for (auto to : G[from.second])
            {
                if(dist[to.second] > dist[from.second] + to.first){
                    dist[to.second] = dist[from.second] + to.first;
                    pos.push(make_pair(dist[to.second], to.second));
                }
            }
        }
        for (int i = 0; i < M; i++)
        {
            //cout << get<0>(w[i]) << ":" << dist[get<0>(w[i])] << " " << get<1>(w[i]) << ":" << dist[get<1>(w[i])] << endl;
            if(abs(dist[get<0>(w[i])] - dist[get<1>(w[i])]) == get<2>(w[i])){
                check[i] = true;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        if(!check[i]) ans++;
        //cout << check[i] << " ";
    }
    //cout << endl;
    cout << ans << endl;
}