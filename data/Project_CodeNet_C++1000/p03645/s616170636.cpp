#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T>
bool PN(T x){ if (x <= 1) return false; if (x == 2) return true; for (int i = 2; i < sqrt(x) + 1; i++) if (x % i == 0) return false; return true;}
const ll MOD = 1e9+7;
long long Comb(int n, int i){long long ans = 1; if(i>n || i < 0) return 0; if(i == 0 || i == n) return 1; else {for(int j = 1; j <= i; ++j){
      ans *=(n+1-j);
      ans /= j;
      ans %= MOD;} }return ans;}

bool visited[200001];

vector< vector<int> > graph(200001);

int check(vector<vector<int>> &graph, int v, int n){
    int ok = 1;
    for(int i = 0; i < graph[v].size(); ++i){
        if(graph[v][i] == n) return ok;
        ok += check(graph, graph[v][i], n);
    }
    return 0;
}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }
    for(auto start: graph[1]){
        for(auto second: graph[start]){
            if(second == n){
                cout << "POSSIBLE" << endl;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main(void){
    solve();
    return 0;
}
