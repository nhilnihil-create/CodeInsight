#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main() {
    int n; cin >> n;
    map<int, int> cnt;
    while (n--) {
        int a; cin >> a;
        cnt[a]++;
    }
    priority_queue<int> pq;
    for (auto &p: cnt) {
        for (int i = 0; i < p.second / 2; i++) pq.emplace(p.first);
    }
    if (pq.size() < 2) return !(cout << 0 << endl);
    int x = pq.top(); pq.pop();
    int y = pq.top(); pq.pop();
    cout << 1LL * x * y << endl;
    return 0;
}
