#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

vector<vector<int>> f(const vector<vector<int>>& dist) {
    int n = dist.size() - 1;
    vector<vector<int>> res(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
    for (int i = 1; i <= n; i++) {
        res[i][i] = 0;
        priority_queue<pair<int, int>> pq;
        pq.push(make_pair(0, i));
        while (pq.size() > 0) {
            auto p = pq.top();
            pq.pop();
            int d = -p.first, index = p.second;
            if (res[i][index] < d) continue;
            for (int j = 1; j <= n; j++) {
                if (res[i][j] > res[i][index] + dist[index][j] && dist[index][j] > 0) {
                    res[i][j]  = res[i][index] + dist[index][j];
                    pq.push(make_pair(-res[i][j], j));
                }
            }
        }
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> path;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, -1));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        path.push_back({a, b, c});
        dist[a][b] = c;
        dist[b][a] = c;
    }
    int res = 0;
    auto min_dist = f(dist);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        a = path[i][0];
        b = path[i][1];
        c = path[i][2];
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                if (min_dist[i][a] + c + min_dist[b][j] == min_dist[i][j]) {
                    flag = 1;
                    break;
                }
                if (min_dist[i][b] + c + min_dist[a][j] == min_dist[i][j]) {
                    flag = 1;
                    break;
                }
            }
        }
        res += 1- flag;
    }
    cout << res << endl;
}
