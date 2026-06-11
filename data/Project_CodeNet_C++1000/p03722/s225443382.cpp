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
    long long ans = 1e18;
    while(true){
        bool flag = false;
        bool flag2 = false;
        for(int i = 0; i < M; i++){
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                flag = true;
                if(e.to == t) flag2 = true; 
            }
        }
        if(!flag) break;
        ans = min(ans, d[t]);
        k++;
        if(k == N && flag2){//閉路があって無限に更新される場合はinf
            cout << "inf" << endl;
            return;
        }
        else if(k == N && !flag2) break;
    }
    cout << -ans << endl;
}
int main(){
    int N, M;
    cin >> N >> M;
    vector<edge> es(M);
    for(int i = 0; i < M; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--;
        b--;
        edge e = {a, b, -c};
        es[i] = e;
    }
    solve(N, M, es, 0, N - 1);
}