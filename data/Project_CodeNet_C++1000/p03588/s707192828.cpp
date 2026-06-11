#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    for (auto& p : v) cin >> p.first >> p.second;
    sort(v.begin(), v.end(), [](const auto& p, const auto& q) {
        return p.first > q.first;
    });
    cout << v[0].first + v[0].second << endl;
}
