#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;

int rec(int v) {
    vector<int> children;
    for (int i = 0; i < G[v].size(); i++) {
        children.push_back(rec(G[v][i]));
    }
    
    sort(children.begin(), children.end(), greater<int>());
    int ret = 0;
    for (int i = 0; i < children.size(); i++) {
        ret = max(i+1+children[i], ret);
    }
    return ret;
}

int main(void){
    int N; cin >> N;
    G.resize(N);
    for (int i = 1; i < N; i++) {
        int a; cin >> a;
        a--;
        G[a].push_back(i);
    }
    
    cout << rec(0) << endl;
}
