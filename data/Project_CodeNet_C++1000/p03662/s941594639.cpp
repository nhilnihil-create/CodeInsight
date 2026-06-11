#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <set>
#include <string>
#include <queue>

using namespace std;

#define rep(i, N) for(int (i) = 0; (i) < (N); (i) ++)
#define INF (int)1e9;
typedef long long ll;

vector<vector<int>> g;

vector<vector<int>> dist;

void dfs(int prev, int node, int start){
    rep(i, g[node].size()){
        int next = g[node][i];
        if(next != prev){
            dist[start][next] = dist[start][node] + 1;
            dfs(node, next, start);
        }
    }
}

int main(){
    int N;
    cin >> N;
    g = vector<vector<int>>(N);
    dist = vector<vector<int>>(2, vector<int>(N));
    rep(i, N - 1){
        int a, b;
        cin >> a >> b;
        a --;
        b --;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(-1, 0, 0);
    dfs(-1, N - 1, 1);
    int tmp = 0;
    rep(i, N){
        if(dist[0][i] <= dist[1][i]){
            tmp ++;
        }
    }
    string ans = "Fennec";
    if(tmp <= N / 2){
        ans = "Snuke";
    }
    cout << ans << endl;

    return 0;
}
