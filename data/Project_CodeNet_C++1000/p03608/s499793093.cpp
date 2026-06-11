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

void f(int index, vector<int>& v, const vector<int>& vr, const vector<vector<int>>& min_dist, int c, int& res) {
    int flag = 1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0) {
            flag = 0;
            v[i] = 1;
            f(i, v, vr, min_dist, c + min_dist[vr[index]][vr[i]], res);
            v[i] = 0;
        }
    }
    if (flag == 1) {
        res = min(res, c);
    }
}

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> vr(r, 0);
    for (int i = 0; i < r; i++) {
        cin >> vr[i];
    }
    vector<vector<int>> path(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        path[a][b] = c;
        path[b][a] = c;
    }
    vector<vector<int>> min_dist(n + 1, vector<int>(n + 1, 0x3f3f3f3f));
    for (int i = 1; i <= n; i++) {
        map<int, unordered_set<int>> mp;
        mp[0].insert(i);
        min_dist[i][i] = 0;
        while (mp.size() > 0) {
            int dist = mp.begin()->first;
            int index = *mp.begin()->second.begin();
            mp[dist].erase(index);
            if (mp[dist].size() == 0) mp.erase(dist);

            for (int j = 1; j <= n; j++) {
                if (dist + path[index][j] < min_dist[i][j]) {
                    if (min_dist[i][j] != 0x3f3f3f3f) {
                        mp[min_dist[i][j]].erase(j);
                        if (mp[min_dist[i][j]].size() == 0) mp.erase(min_dist[i][j]);
                    }
                    min_dist[i][j] = dist + path[index][j];
                    mp[min_dist[i][j]].insert(j);
                }
            }
        }
    }
    
    int res = 0x3f3f3f3f;
    vector<int> v(r, 0);
    for (int i = 0; i < r; i++) {
        v[i] = 1;
        f(i, v, vr, min_dist, 0, res);    
        v[i] = 0;
    }
    cout << res << endl;
}
