#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

int dfs(int node, vector<vector<int>> &edge){
    
    priority_queue<int,vector<int>,greater<int>> que;
    for(auto x:edge[node]){
        que.push(dfs(x, edge));
    }

    int n=edge[node].size();
    int d=0;
    while((int)que.size()){
        d=max(d,que.top()+n);
        que.pop();
        n--;
    }

    return d;
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> edge(N,vector<int>(0));
    for(int i=1; i<N; i++){
        int a;
        cin >> a;
        a--;
        edge[a].push_back(i);
    }

    cout << dfs(0, edge) << endl;;
}