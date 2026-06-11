#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>

using namespace std;

vector <int> edges[100000];
vector <int> reverse_edges[100000];
int in_degree[100000];
vector <int> tp_ord;
bool used[100000];
int dp[100000];
void dfs(int cur){
    used[cur] = true;
    for(int i = 0; i < edges[cur].size(); i++){
        int next = edges[cur][i];
        if(!used[next]){
            dfs(next);
        }
    }
    tp_ord.push_back(cur);
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N - 1; i++){
        int a;
        cin >> a;
        edges[i + 1].push_back(a - 1);
        reverse_edges[a - 1].push_back(i + 1);
        in_degree[a - 1] ++;
    }

    for(int i = 0; i < N; i++){
        if(in_degree[i] == 0){
            dfs(i);
        }
    }
    reverse(tp_ord.begin(), tp_ord.end());
    for(int i = 0; i < N; i++){
        int cur = tp_ord[i];
        int max_depth = 0;
        int min_depth = INT_MAX;
        if(reverse_edges[cur].size() == 0){
            dp[cur] = 0;
            continue;
        }

        vector <int> prev_depths;
        prev_depths.push_back(0);
        for(int j = 0; j < reverse_edges[cur].size(); j++){
            prev_depths.push_back(1 + dp[reverse_edges[cur][j]]);
        }
        sort(prev_depths.begin(), prev_depths.end());
        for(int j = 0; j < prev_depths.size(); j++){
            dp[cur] = max(dp[cur], prev_depths[prev_depths.size() - 1 - j] + j);
        }
        //cout << cur << " " << dp[cur] << endl;
    }
    cout << dp[0] << endl;
    return 0;
}
