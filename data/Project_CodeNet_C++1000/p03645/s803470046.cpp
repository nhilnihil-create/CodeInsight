#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

typedef vector<vector<int>> Graph;

const int INF = 1e9;
const long long LINF = 1e18;

int main() {
    int N, M;
    cin >> N >> M;

    Graph G(N, vector<int>());

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }

    for (size_t i = 0; i < G[0].size(); i++) {
        int x = G[0][i];
        for (size_t j = 0; j < G[x].size(); j++) {
            if (G[x][j] == N - 1) {
                cout << "POSSIBLE" << endl;
                return 0;
            }
        }
        
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
