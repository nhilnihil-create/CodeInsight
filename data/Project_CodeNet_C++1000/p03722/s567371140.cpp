#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

ll INF = (1LL << 60);

class Graph{
public:
    struct edge{
        int from, to;
        ll cost;
    };

    int N;
    vector<ll> d;
    vector<edge> E;

    Graph(int _N){
        N = _N;
        d.resize(N, INF);
    }

    void make_edge(int s, int t, ll c){
        E.push_back(edge{s, t, c});
    }

    bool bellman_ford(int s){
        d[s] = 0;
        for(int i = 0; i < 3 * N; i++){
            bool update = false;
            for(int j = 0; j < (int)E.size(); j++){
                edge e = E[j];
                if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                    //cout << e.from << "  " << e.to << endl;
                    update = true;
                    d[e.to] = d[e.from] + e.cost;
                    if(e.to == N - 1 && i >= N - 1) return true;
                }
            }

            if(!update) return false;
        }

        return false;
    }

    ll get_cost(int t){
        return d[t];
    }
};

int main(){
    int N, M;
    cin >> N >> M;

    Graph gr = Graph(N);
    for(int i = 0; i < M; i++){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        gr.make_edge(a - 1, b - 1, -c);
    }

    if(gr.bellman_ford(0)){
        cout << "inf" << endl;
    } else {
        cout << -gr.get_cost(N - 1) << endl;
    }

    return 0;
}