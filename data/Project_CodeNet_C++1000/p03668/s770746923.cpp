#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> G;

int dfs(int s, int par){
    int ret = 0;
    for(int t : G[s]){
        if(t == par) continue;
        ret ^= 1+dfs(t, s);
    }
    return ret;
}

int main(){
    cin >> N;
    G.resize(N);
    for(int i=0; i<N-1; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    cout << (dfs(0, -1)==0 ? "Bob" : "Alice") << endl;
    return 0;
}
