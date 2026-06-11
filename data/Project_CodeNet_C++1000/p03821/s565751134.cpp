#include <iostream>
#include <array>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int main(void) {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    std::vector<pair<int,int>> v(n);
    for (auto& el : v) {
        cin >> el.first >> el.second;
    }

    int64_t ad = 0;
    for (int i = n - 1; i >= 0; i--) {
        int64_t cur = (v[i].second - (v[i].first + ad) % v[i].second) % v[i].second;
        ad += cur;
    }
    cout << ad << endl;
}
