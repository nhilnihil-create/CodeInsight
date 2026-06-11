#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph(100001);

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
    }

    vector<int> done(n + 1);
    deque<int> dq;
    dq.push_back(1);
    while (true) {
        bool ok = true;
        int v = dq.back();
        done.at(v) = true;
        for (int i = 0; i < (int)graph.at(v).size(); i++) {
            if (!done.at(graph.at(v).at(i))) {
                dq.push_back(graph.at(v).at(i));
                ok = false;
                break;
            }
        }
        if (ok) break;
    }
    while (true) {
        bool ok = true;
        int v = dq.front();
        done.at(v) = true;
        for (int i = 0; i < (int)graph.at(v).size(); i++) {
            if (!done.at(graph.at(v).at(i))) {
                dq.push_front(graph.at(v).at(i));
                ok = false;
                break;
            }
        }
        if (ok) break;
    }

    cout << dq.size() << endl;
    for (auto v: dq) {
        cout << v << " ";
    }
    cout << endl;
}