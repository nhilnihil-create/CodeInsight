#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n; cin >> n;
    map<int, int> cnt;
    while (n--) {
        int a; cin >> a;
        cnt[a]++;
    }
    vector<long long> v;
    for (auto &p: cnt) {
        for (int i = 0; i < p.second / 2; i++) v.emplace_back(p.first);
    }
    if (v.size() < 2) return !(cout << 0 << endl);
    sort(v.rbegin(), v.rend());
    cout << v[0] * v[1] << endl;
    return 0;
}
