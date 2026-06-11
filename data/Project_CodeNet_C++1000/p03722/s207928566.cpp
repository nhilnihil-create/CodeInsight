#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_V 1000
#define INF 100000000000000

struct edge {
    long long from; //出発点
    long long to;   //到達点
    long long cost; //移動コスト
};

long long V; //頂点の数
long long E; //辺の数
long long d[MAX_V +1]; //始点からそこまで行くのにかかるコスト
vector<edge> edges; //移動の情報を保存する
bool negative_cycle=0;

vector<long long> Grainv[1001];
bool cangoal[1001];

void bellman_ford(long long S){
    fill(d, d+V+1, INF); //すべての頂点をINFにする
    d[S] = 0; //始点を0にする
    long long i;
    for (i = 0; i < V; i++) {
        for (long long j = 0; j < (long long)edges.size(); j++) {

            struct edge e = edges[j];

            if ((d[e.to] > d[e.from] + e.cost)&&(d[e.from]<INF)) {  //移動した後のコストが小さいと、頂点のコストを更新：ただしfromがINFでないとする
                d[e.to] = d[e.from] + e.cost;
                if(cangoal[e.from]==1){
                    if (i == V-1) {         //頂点の数と同じ回数ループすると、負の閉路があるのでループをぬける
                        negative_cycle=1;
                        break;
                    } 
                }
            }
        }
    }
}

void dfs_for_goal(long long v){
    long long i;
    for(i=0; i<Grainv[v].size(); i++){
        if(cangoal[Grainv[v][i]]==0){
            cangoal[Grainv[v][i]]=1;
            dfs_for_goal(Grainv[v][i]);
        }
    }
    
}

int main()
{
    cin >> V;
    cin >> E;

    long long S=1; //始点
    long long G=V; //終点

    long long i;
    for (i = 0; i < E; i++) {
        struct edge add;
        cin >> add.from;
        cin >> add.to;
        cin >> add.cost;
        add.cost=-add.cost;
        edges.push_back(add);

        Grainv[add.to].push_back(add.from);
    }

    fill(cangoal,cangoal+V+1,0);
    cangoal[G]=1;
    dfs_for_goal(G);

    bellman_ford(S);

    if(negative_cycle==0){    
        cout <<  -d[G] << endl;
    }else{
        cout << "inf" << endl;
    }
    system("pause");
    return 0;
}
