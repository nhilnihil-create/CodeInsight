#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> p, q;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1)p.insert(b);
        if (b == n)q.insert(a);
    }

    bool ret = false;
    for (auto x:p) {
        if (q.find(x) != q.end())ret = true;
    }
    cout << (ret ? "POSSIBLE" : "IMPOSSIBLE") << endl;
    return 0;
}