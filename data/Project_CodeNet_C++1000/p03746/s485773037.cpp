#include <iostream>
#include <vector>
#include <deque>

using namespace std;
using graph = vector<vector<int>>;


int main() {
    int n, m;
    cin >> n >> m;
    graph g(n+1);
    while(m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    deque<int> path;
    path.push_back(1);
    vector<int> visited(n+1);
    int v = 1;
    visited[1] = true;
    bool cont = true;
    while(cont) {
        cont = false;
        for(auto&& w : g[v]) {
            if(!visited[w]) {
                visited[w] = true;
                path.push_back(w);
                v = w;
                cont = true;
                break;
            }
        }
    }
    v = 1;
    cont = true;
    while(cont) {
        cont = false;
        for(auto&& w : g[v]) {
            if(!visited[w]) {
                visited[w] = true;
                path.push_front(w);
                v = w;
                cont = true;
                break;
            }
        }
    }
    cout << path.size() << endl << path.front();
    path.pop_front();
    while(!path.empty()) cout << " " << path.front(), path.pop_front();
    cout << endl;
}
