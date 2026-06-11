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

class Graph{
public:
    int N;
    vector<vector<int>> G;
    vector<bool> used;

    Graph(int n){
        N = n;
        G.resize(N);
        used.resize(N, false);
    }

    void make_edge(int s, int t){
        G[s].push_back(t);
        G[t].push_back(s);
    }

    vector<int> find_pass(int _v){
        vector<int> ret;
        int v = _v;

        while(true){
            ret.push_back(v);
            used[v] = true;
            bool found = false;

            for(int i = 0; i < (int)G[v].size(); i++){
                if(!used[G[v][i]]){
                    v = G[v][i];
                    found = true;
                    break;
                }
            }

            if(found) continue;
            else break;
        }

        return ret;
    }
};

int main(){
    int N, M;
    cin >> N >> M;

    Graph g = Graph(N);
    for(int i = 0; i < M; i++){
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        g.make_edge(s, t);
    }

    vector<int> v1 = g.find_pass(0);
    vector<int> v2 = g.find_pass(0);

    int sz1 = v1.size();
    int sz2 = v2.size();

    cout << sz1 + sz2 - 1 << endl;
    for(int i = sz1 - 1; i >= 0; i--){
        cout << v1[i] + 1 << " ";
    }
    for(int i = 1; i < sz2; i++){
        cout << v2[i] + 1 << " ";
    }

    cout << endl;
    return 0;
}
