#include <bits/stdc++.h>

using namespace std;

vector<int> G[100005];
bool used[100005];


int next_vertex(int v) {
    for (auto vertex : G[v]) {
        if (!used[vertex]) return vertex;
    }
    return -1;
}


int main() {
    int n, m;
    cin >> n >> m;

    map<int, int> mp;
    while (m--) {
        int a, b;
        cin >> a;
        cin >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    deque<int> dq;
    dq.push_back(0);

    for (auto &x:used) x = false;
    used[0] = true;

    int v;
    while ((v = next_vertex(dq.back())) != -1) {
        dq.push_back(v);
        used[v] = true;
    }

    while ((v = next_vertex(dq.front())) != -1) {
        dq.push_front(v);
        used[v] = true;
    }

    cout << dq.size() << endl;
    for (auto itr = dq.begin(); itr != dq.end(); ++itr) {
        cout << (*itr) + 1;
        (itr + 1 == dq.end()) ? (cout << endl) : (cout << " ");
    }
    return 0;
}
