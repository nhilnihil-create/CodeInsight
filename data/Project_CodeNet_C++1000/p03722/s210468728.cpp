#include <bits/stdc++.h>
using namespace std;
//以下雛形を記す
long long INF =  -10000000000000000;
struct edge{
    int from;
    int to;
    long long cost;
};

int main(){
    int N, M;//Vは頂点、Kは辺の数
    cin >> N >> M;
    vector<edge> es(M);
    for(int i = 0; i < M; i++){
        cin >> es[i].from >> es[i].to >> es[i].cost;
        es[i].from--;
        es[i].to--;
       // es[i].cost *= -1;
    }
    vector<long long> d(N);//各頂点までの距離
    for(int i = 0; i < N; i++) d[i] = INF;
    d[0] = 0;
    int n = 0;
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < M; j++){
            edge e = es[j];
            if(d[e.from] != INF && d[e.to] < d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
            }
        }
    }
    long long ans = d[N - 1];
    bool neg[N];
    for(int i = 0; i < N; i++) neg[i] = false;
    for(int i = 0; i < N; i++){//もう1セット更新し直して、最後が更新されていたらinfを出力
        for(int j = 0; j < M; j++){
            edge e = es[j];
            if(d[e.from] != INF){
                if(d[e.to] < d[e.from] + e.cost){
                    d[e.to] = d[e.from] + e.cost;
                    neg[e.to] = true;
                }
                if(neg[e.from]) neg[e.to] = true;//d[e.from]が更新されていたら、その次の更新でd[e,to]は当然更新される
            }
        }
    }
    if(neg[N-1]) cout << "inf" << endl;
    else cout << ans << endl;
}