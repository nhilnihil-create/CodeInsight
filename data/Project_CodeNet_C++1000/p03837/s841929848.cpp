#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

const int inf = 1e9;
const int mod = 1e9+7;

struct edge {
    int from, to, cost;
};

typedef pair<int, int> P;
typedef vector<vector<edge> > G;

G graph;
int n, m;

int d[105][105];
bool used[105][105];
vector<edge> dist;

void warshall_floyd(){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main(void){
    cin >> n >> m;
    graph = G(n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j){
                d[i][j] = 0;
            }else{
                d[i][j] = inf;
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<m; i++){
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        d[x][y] = c;
        d[y][x] = c;
        edge e;

        e.from = x;
        e.to = y;
        e.cost = c;
        dist.push_back(e);
        e.from = y;
        e.to = x;
        e.cost = c;
        dist.push_back(e);

    }

    warshall_floyd();
    int ans = 0;
    for(int i=0; i<dist.size(); i++){
        bool flag = false;
        for(int s=0; s<n; s++){
            for(int t=0; t<n; t++){
                if(d[s][dist[i].from] + dist[i].cost + d[dist[i].to][t] == d[s][t]){
                    flag = true;
                }
            }
        }
        if(!(flag)){
            ans++;
        }
    }
    cout << ans/2 << endl;
    return 0;
}