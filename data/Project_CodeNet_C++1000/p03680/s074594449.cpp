#include<bits/stdc++.h>
using namespace std;

void dfs(int vertex, unordered_map<int, vector<int>> &m, vector<bool>& visited, vector<int>& count, int hop){
    if(visited[vertex]) return ;
    visited[vertex] = true;
    count[vertex] = min(hop, count[vertex]);
    if(vertex == 1) return;
    for(int i=0;i<m[vertex].size();i++){
        if(!visited[m[vertex][i]]){
            dfs(m[vertex][i], m, visited, count, hop+1);
        }
    }
    return ;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];

    unordered_map<int, vector<int>> m;
    for(int i=0;i<n;i++){
        m[i].push_back(arr[i]-1);
    }
    vector<bool> visited(n,false);
    vector<int> count(n,INT_MAX);
    dfs(0, m, visited, count, 0);
    if(visited[1]) cout<<count[1]<<endl;
    else cout<<-1<<endl;
}