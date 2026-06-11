#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    vector<int> included(n);
    deque<int> path;

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a -= 1;
        b -= 1;

        graph[a].push_back(b);
        graph[b].push_back(a);

        if(i == 0){
            path.push_front(a);
            path.push_back(b);
            included[a] = 1;
            included[b] = 1;
        }
    }

    
    while(1){
        int a = path.front();
        bool flag = true;
        for(int v : graph[a]){
            if(included[v] == 0){
                included[v] = 1;
                path.push_front(v);
                flag = false;
                break;
            }
        }
        if(flag == true) break;
    }
    while(1){
        int b = path.back();
        bool flag = true;
        for(int v : graph[b]){
            if(included[v] == 0){
                included[v] = 1;
                path.push_back(v);
                flag = false;
                break;
            }
        }
        if(flag == true) break;
    }

    cout << path.size() << endl;
    while(1){
        cout << path.front() + 1;
        path.pop_front();
        if(path.empty() == true) break;
        cout << " ";
    }
    cout << endl;
    return 0;
}