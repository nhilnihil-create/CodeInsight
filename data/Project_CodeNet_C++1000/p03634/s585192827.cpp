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

int main() {        
    int n;
    cin >> n;
    unordered_map<int, unordered_map<int, int>> um;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        um[a][b] = c;
        um[b][a] = c;
    }
    int q, k;
    cin >> q >> k;
    vector<long long int> dist(n + 1, -1);
    dist[k] = 0;
    priority_queue<pair<long long int, int>> pq;
    pq.push(make_pair(0, k));
    while (pq.size() > 0) {
        auto p = pq.top();
        pq.pop();
        long long int d = -p.first;
        int index = p.second;
        if (dist[index] != d) continue;
        for (auto pp : um[index]) {
            if (dist[pp.first] == -1 || pp.second + d < dist[pp.first]) {
                dist[pp.first] = pp.second + d;
                pq.push(make_pair(-dist[pp.first], pp.first));
            }
        }
    }
    for (int i = 0; i < q; i++) {

        int a, b;
        cin >> a >> b;
        cout << dist[a] + dist[b] << endl;
    }
}
