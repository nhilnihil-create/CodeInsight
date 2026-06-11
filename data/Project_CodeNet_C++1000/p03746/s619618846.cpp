// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef int_fast64_t ll;
// inline void fastio(){cin.tie(nullptr); cout.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15);}

int main() {
    // fastio();
    int N, M, a, b, s, t;
    bool f;
    cin >> N >> M;
    vector<vector<int>> G(N + 1, vector<int>(0));
    REP(i, M) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    s = 1;
    t = G[s][0];
    list<int> ans = {s, t};
    vector<int> visited(N + 1, 0);
    visited[s] = visited[t] = 1;
    while(true) {
        visited[s] = 1;
        f = false;
        for(auto& x : G[s]) {
            if(visited[x] == 0) {
                s = x; f = true;
                ans.push_front(s);
                break;
            }
        }
        if(f) continue;
        break;
    }
    while(true) {
        visited[t] = 1;
        f = false;
        for(auto& x : G[t]) {
            if(visited[x] == 0) {
                t = x; f = true;
                ans.push_back(t);
                break;
            }
        }
        if(f) continue;
        break;
    }
    cout << ans.size() << "\n";
    for(auto it = ans.begin(); it != ans.end(); it++) cout << *it << " ";
    cout << endl;
    return 0;
}