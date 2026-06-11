#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 100010;
const int INFTY = 1<<21;
const int WHITE = 1;
const int BLACK = 2;
const int GRAY = 3;
vector<int> list[MAX];
int N;

vector<int> bfs(int s){
    vector<int> d(N,INFTY);
    queue<int> Q;
    d[s] = 0;
    Q.push(s);
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(auto v : list[u]){
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
    }
    return d;
}

vector<int> dijkstra(int s){
    vector<int> d(N,INFTY);
    vector<int> color(N, WHITE);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > Q;

    d[s] = 0;
    color[s] = GRAY;
    Q.push({d[s], s});
    while(!Q.empty()){
        auto tmp = Q.top(); Q.pop();
        int u = tmp.second;
        color[u] = BLACK;
        
        if(d[u] < tmp.first) continue;

        for(auto v : list[u]){
            if(color[v] == BLACK) continue;
            if(d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                color[v] = GRAY;
                Q.push({d[v],v});
            }
        }
    }
    return d;
}

int main(){
    cin >> N;
    if(N == 2){
        cout << "Snuke" << endl;
        return 0;
    }

    int a,b;
    for(int i=0;i<N-1;i++){
        cin >> a >> b;
        a--; b--;
        list[a].push_back(b);
        list[b].push_back(a);
    }

    vector<int> d_1 = dijkstra(0);
    vector<int> d_N = dijkstra(N-1);
    int count_1 = 0;
    int count_N = 0;
    for(int i=1;i<N-1;i++){
        if(list[i].size() == 0){  // i-th node is a leaf
            int j = list[i][0];  // j is i-th's parent
            if(d_1[j] > d_N[j]){
                count_N++;
            }else{
                count_1++;
            }
        }else{
            if(d_1[i] > d_N[i]){
                count_N++;
            }else{
                count_1++;
            }
        }
    }

    if(count_1 > count_N){
        cout << "Fennec" << endl;
    }else{
        cout << "Snuke" << endl;
    }
    return 0;
}