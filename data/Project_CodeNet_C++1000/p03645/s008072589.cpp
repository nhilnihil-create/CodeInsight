#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
const int INF = 1000000007;

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

int main(){
    int N, M;
    cin >> N >> M;
    Graph G(N);
    rep(i, M){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<bool> visited(N, false);
    queue<int> que;
    visited[0] = true;

    for(int j : G[0]){
        if(visited[j]) continue;
        visited[j] = true;
        que.push(j);
    }

    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int j : G[v]){
            visited[j] = true;
        }
    }

    if(visited[N-1]) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;

}