#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define PI acos(-1)

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    Rep(i, M) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    Rep(i, graph[0].size()) {
        int v = graph[0][i];
        Rep(j, graph[v].size()) {
            if (graph[v][j] == N - 1) {
                puts("POSSIBLE");
                return 0;
            }
        }
    }
    puts("IMPOSSIBLE");
    return 0;
}