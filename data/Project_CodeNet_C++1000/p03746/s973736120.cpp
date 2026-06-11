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

bool used[100000];
vector <int> path[2];

void dfs(int v, int path_ind){
    used[v] = true;
    path[path_ind].push_back(v);
    for(int i = 0; i < edges[v].size(); i++){
        if(!used[edges[v][i]]){
            dfs(edges[v][i], path_ind);
            break;
        }
    }
}

int main(){
    int N;
    int M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int A;
        int B;
        cin >> A >> B;
        edges[A-1].push_back(B - 1);
        edges[B-1].push_back(A - 1);
    }

    if(edges[0].size() < 2){
        dfs(0, 0);
    } else {
        dfs(0, 0);
        for(int i = 0; i < edges[0].size(); i++){
            if(!used[edges[0][i]]){
                dfs(edges[0][i], 1);
                break;
            }
        }
    }
    
    vector <int> ans = path[0];
    reverse(ans.begin(), ans.end());
    ans.insert(ans.end(), path[1].begin(), path[1].end());

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        if(i != ans.size() - 1){
            cout << ans[i] + 1 << " ";
        } else {
            cout << ans[i] + 1<< endl;
        }
    }
    return 0;
}
