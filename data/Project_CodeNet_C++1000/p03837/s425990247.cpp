#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<std::pair<ll,ll>>>;

using namespace std;

int main() {
    ll N,M;
    cin >> N >> M;
    graph G(N);
    for (int i = 0; i < M; ++i) {
        ll a,b,c;
        cin >> a >> b >>c;
        a--;b--;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    ll dist[N][N];
    for (int xi = 0; xi < N; ++xi) {
        for (int yi = 0; yi < N; ++yi) {
            if(yi == xi){
                dist[yi][xi] = 0;
            }else{
                dist[yi][xi] = 1ll << 50;
            }
        }
    }
    for (int i = 0; i < G.size(); ++i) {
        for (int j = 0; j < G[i].size(); ++j) {
            dist[i][G[i][j].first] = G[i][j].second;
            dist[G[i][j].first][i] = G[i][j].second;
        }
    }
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i <N; ++i) {
            for (int j = 0; j < N; ++j) {
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    dist[j][i] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    ll count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < G[i].size(); ++j) {
            bool judge = false;
            for (int k = 0; k < N; ++k) {
                if(dist[k][i] + G[i][j].second == dist[k][G[i][j].first]){
                    judge = true;
                }
            }
            if(!judge){
                count++;
            }
        }
    }
    cout << count/2 << endl;
}
