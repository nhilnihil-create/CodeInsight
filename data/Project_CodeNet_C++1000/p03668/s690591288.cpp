#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;

vector<int> tree[100000];
int dfs(int v, int p){
    int res = 0;
    for(int u : tree[v])if(u != p){
        res ^= (dfs(u, v) + 1);
    }
    return res;
}

int main(){

    int N;
    cin >> N;

    rep(i, N - 1){
        int x, y;
        cin >> x >> y;
        x--; y--;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    cout << (dfs(0, -1) ? "Alice\n" : "Bob\n");
    return 0;

}