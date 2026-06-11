#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define fs first
#define sc second

int n;
vector<int> edge[100100];

// Pのfirstが最短距離、secondが頂点番号
int prev_node[100100];
int d[100100];

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+n, INT_MAX);

    d[s] = 0;
    que.push(P(0, s));

    while(!que.empty()){
        P p = que.top(); que.pop();
        int v = p.sc;
        if(d[v] < p.fs) continue;
        for(int i = 0; i < edge[v].size(); i++){
            int e = edge[v][i];  //vからeへの道
            if(d[e] > d[v] + 1){
                d[e] = d[v] + 1;
                que.push(P(d[e], e));
                prev_node[e] = v;
            }
        }
    }
}

ll child[100100];

ll tree_child_dfs(int s, int pre){
    ll res = 0;
    for(int i = 0; i < edge[s].size(); i++){
        if(edge[s][i] == pre)   continue;

        res += tree_child_dfs(edge[s][i], s);
    }
    res++;
    child[s] = res;
    return res;
}


int main(){
    cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b;   cin >> a >> b;
        a--; b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dijkstra(0);
    tree_child_dfs(0, -1);

    int dis = (d[n-1] - 1) / 2;
    int node = n-1;
    for(int i = 0; i < dis; i++){
        node = prev_node[node];
    }

    ll sunuke = child[node];
    ll fenec = n - child[node];
    if(sunuke >= fenec){
        cout << "Snuke" << endl;
    }
    else{
        cout << "Fennec" << endl;
    }


    return 0;
}

