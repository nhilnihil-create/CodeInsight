#include <bits/stdc++.h>
using namespace std;

vector<int> edges[100000];

int dfs(int i, int prev){
    int ret = 0;
    for(auto j : edges[i]){
        if(j != prev) ret ^= dfs(j, i) + 1;
    }
    return ret;
}

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N-1; i++){
        int x, y;
        cin >> x >> y;
        edges[x-1].push_back(y-1);
        edges[y-1].push_back(x-1);
    }

    int gr = dfs(0, -1);
    cout << (gr!=0 ? "Alice" : "Bob") << endl;
    return 0;
}