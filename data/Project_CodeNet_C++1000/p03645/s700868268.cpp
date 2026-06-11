#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int> > to(N);
    rep(i, M){
        int a, b; cin >> a >> b;
        a--;
        b--;
        to[a].push_back(b);
    }

    int f = to[0].size();
    queue<int> q;
    for (int i = 0; i < f; i++){
        q.push(to[0][i]);
    }

    bool ok = false;
    while(!q.empty()){
        int x = q.front(); q.pop();
        int y = to[x].size();
        for (int i = 0; i < y; i++){
            if(to[x][i] == N-1){
                ok = true;
            }
        }
    }

    if(ok){
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    

    return 0;
}