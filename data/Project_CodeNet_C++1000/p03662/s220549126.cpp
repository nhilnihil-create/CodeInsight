#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int N;
vector<int> route;
vector<vector<int>> graph(1e5+1);
vector<bool>    used(1e5+1, false);

bool dfs(int v){
    if(v == N){
        route.emplace_back(v);
        return true;
    }
    used[v] = true;
    for(auto& itr : graph[v]){
        if(!used[itr] && dfs(itr)){
            route.emplace_back(v);
            return true;
        }
    }
    return false;
}
int main(){
    cin >> N;
    for(int i = 0;i < N-1;i++){
        int ai, bi;
        cin >> ai >> bi;
        graph[ai].emplace_back(bi);
        graph[bi].emplace_back(ai);
    }
    dfs(1);
    reverse(route.begin(), route.end());
    int id = (route.size()-1)/2;
    int a = route[id];
    int b = route[id+1];
    for(int i = 0;i < graph[a].size();i++) if(graph[a][i] == b)  graph[a].erase(graph[a].begin()+i);
    for(int i = 0;i < graph[b].size();i++) if(graph[b][i] == a)  graph[b].erase(graph[b].begin()+i);
    for(int i = 1;i <= N;i++)   used[i] = false;
    queue<int>  que;
    que.push(1);
    int count = 0;
    while(!que.empty()){
        int v = que.front();
        que.pop();
        if(used[v]) continue;
        used[v] = true;
        count++;
        for(auto itr : graph[v])    que.emplace(itr);
    }
    if(count*2 > N) cout << "Fennec" << endl;
    else    cout << "Snuke" << endl;
}