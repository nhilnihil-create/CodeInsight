#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <string>
#include <set>
#include <bitset>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <map>
#include <cstdlib>

using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
template <class T>
using Vvec = vector<vector<T> >;
using Graph = Vvec<int>;

template <class T>
void debug(T& v)
{
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

void dfs(Graph& graph, vector<ll>& dp, int tmp = 0, int from = -1){
    for(auto& to: graph[tmp]){
        if(to != from){
            dfs(graph, dp, to, tmp);
            dp[tmp] ^= dp[to]+1;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    Graph graph(N);
    for(int i=0; i<N-1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<ll> dp(N);
    dfs(graph, dp);

    cout << ((dp[0]) ? "Alice" : "Bob") << "\n";
}