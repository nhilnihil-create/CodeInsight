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
    while(true){
        bool flag = false;
        bool flag2 = true;
        for(int i = 0; i < M; i++){
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] < d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                if(n >=N && e.to == N - 1) flag2 = false;
                flag = true;
            }
        }
        n++;
        if(!flag){
            cout << d[N - 1] << endl;
            break;
        }
        if(n >= N && flag2 == false){//閉路があり、閉路から抜け出して目標点までの距離が更新される場合
            cout << "inf" << endl;
            break;
        }
        else if(n >= 2*N && flag2 == true){
            cout << d[N - 1] << endl;
            break;
        }
    }
}