#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> edge(1e5, vector<int>());

void dfs(int start, int d, vector<int>& dist) {
    if (dist[start] > 0) return;
    
    dist[start] = d;
    for (int next:edge[start]) {
        dfs(next, d + 1, dist);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
      	--a; --b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<int> distF(N), distS(N);
    dfs(0, 1, distF); dfs(N - 1, 1, distS);
    long long cnt = 0;
    for (int i = 0; i < N; i++) {
  // 	cout << distF[i] << " " << distS[i] << endl;
        cnt += distF[i] > distS[i]? -1: 1;
    }
    cout << (cnt > 0? "Fennec": "Snuke") << endl;
}
