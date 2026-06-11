#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    deque<int> ans = {1};
    vector<bool> v(n+1, false);
    v[1] = true;
    // front
    while (true) {
        const auto p = ans.front();
        v[p] = true;
        bool finished = true;
        for (const auto &r : g[p]) {
            if (!v[r]) {
                v[r] = true;
                ans.emplace_front(r);
                finished = false;
                break;
            }
        }
        if (finished) break;
    }
    // back
    while (true) {
        const auto p = ans.back();
        v[p] = true;
        bool finished = true;
        for (const auto &r : g[p]) {
            if (!v[r]) {
                v[r] = true;
                ans.emplace_back(r);
                finished = false;
                break;
            }
        }
        if (finished) break;
    }

    // out
    cout << ans.size() << endl;
    for (size_t i = ans.size(); i--; ) {
        cout << ans[i];
        if (i) cout << " "; else cout << endl;
    }

    
}
