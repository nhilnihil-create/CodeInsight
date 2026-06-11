#include <iostream>
#include <vector>
using namespace std;
long long INF = 1e18;
struct edge{
    int from;
    int to;
    long long cost;
};
void solve(int N, int M, vector<edge> &es, int s, int t){
    vector<long long> d(N);//各頂点までの距離
    for(int i = 0; i < N; i++) d[i] = INF;
    d[s] = 0;
    long long k = 0;
    while(true){
        bool flag = false;
        for(int i = 0; i < M; i++){
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                flag = true;
            }
        }
        if(!flag || k == N) break;
        k++;
    }
    long long ans = d[t];
    k = 0;
    while(true){
        for(int i = 0; i < M; i++){
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = -INF;
            }
        }
        k++;
        if(k == N) break;
    }
    if(d[t] == -INF) cout << "inf" << endl;
    else cout << -ans << endl;
}
int main(){
    int N, M;
    cin >> N >> M;
    vector<edge> es(M);
    for(int i = 0; i < M; i++){
        int x, y;
        long long c;
        cin >> x >> y >> c;
        x--;
        y--;
        edge e = {x, y, -c};
        es[i] = e;
    }
    solve(N, M, es, 0, N - 1);
}