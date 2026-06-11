#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[100005];  // 木の情報を格納

int dfs(int parent){
    if(graph[parent].size() == 0)    return 0;

    vector<int> depth;  // 親ノードparentの子ノードの部分木の深さ
    for(int i = 0; i < (int)graph[parent].size(); ++i){
        int child = graph[parent][i];
        depth.push_back(dfs(child));
    }
    sort(depth.begin(), depth.end(), greater<int>());

    int ret = 0;
    for(int i = 0; i < (int)depth.size(); ++i){
        ret = max(ret, depth[i] + i + 1);
    }

    return ret;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i){
        int a;
        cin >> a;
        --a;
        graph[a].push_back(i);
    }

    cout << dfs(0) << endl;
}
