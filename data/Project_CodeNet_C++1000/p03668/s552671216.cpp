#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int n;
vector< vector<int> > graph(100100, vector<int>());
vector<bool> visited(100100, false);

int dfs(int now) {
    int g = 0;
    for(int i = 0; i < graph.at(now).size(); ++i) {
        if(!visited.at(graph.at(now).at(i))) {
            visited.at(graph.at(now).at(i)) = true;
            g ^= dfs(graph.at(now).at(i));
        }
    }
    return g+1;
}

int main() {
    cin >> n;
    for(int i = 0; i < n-1; ++i) {
        int a, b; cin >> a >> b;
        a--; b--;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
    }
    visited.at(0) = true;
    int ans = dfs(0)-1;

    if(ans == 0) cout << "Bob" << endl;
    else cout << "Alice" << endl;
}