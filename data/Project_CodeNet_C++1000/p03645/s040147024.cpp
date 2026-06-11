#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N, M;
    cin >> N >> M;
    vec<vec<int>> G(N,vec<int>());
    
    rep(i,M){
        int a,b;
        cin >> a >> b;
        --a,--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    bool ans = false;
    auto dfs = [&](int i) {
        for (auto e : G[i]) {
            if(e==(N-1)) ans = true;
        }
    };

    for(auto e:G[0]){
        if(e==(N-1)) ans = true;
        else dfs(e);
    }

    cout << (ans?"POSSIBLE":"IMPOSSIBLE") << endl;    
}
