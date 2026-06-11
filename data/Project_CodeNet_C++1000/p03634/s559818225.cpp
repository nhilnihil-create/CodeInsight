#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
typedef pair<long long, int> P;
struct edge{
    int to;
    long long cost;
};
int main(){
    int N;
    cin >> N;
    vector<edge> G[N];
    for(int i = 0; i < N - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edge e = {a, c}, e2 = {b, c};
        G[b].push_back(e);
        G[a].push_back(e2);
    }
    priority_queue<P> q;
    int Q, K;
    cin >> Q >> K;
    K--;
    long long INF = 1e18;
    vector<long long> d(N, INF);
    d[K] = 0;
    q.push(P(0, K));
    while(!q.empty()){
        P v = q.top();
        q.pop();
        if(v.first > d[v.second]) continue;
        long long dis = v.first;
        for(edge e:G[v.second]){
            if(d[e.to] > dis + e.cost){
                d[e.to] = dis + e.cost;
                q.push(P(d[e.to], e.to));
            }
        }
    }
    for(int i = 0; i < Q; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        cout << d[x] + d[y] << endl;
    }
}