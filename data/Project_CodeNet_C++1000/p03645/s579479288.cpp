#include <bits/stdc++.h>
using namespace std;
#define int long long
int INF = 1e9+7;
signed main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>>vec(N);
    for(int i = 0; i < M; i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i = 0; i < vec[0].size(); i++) {
        int X = vec[0][i];
        for(int j = 0; j < vec[X].size(); j++) {
            if(vec[X][j] == N-1) {
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
}