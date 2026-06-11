#include <bits/stdc++.h>

using namespace std;

deque<int> path;
int n, m, a, b;
vector<int> adj[100005];
bool onPath[100005];

int main() {
    cin >> n >> m;
    memset(onPath, 0, sizeof(bool) * (n+1));
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    path.push_front(1);
    onPath[1] = true;
    bool good = false;
    while (!good) {
        good = true;
        int front = path.front();
        for (int i : adj[front]) {
            if (!onPath[i]) {
                path.push_front(i);
                onPath[i] = true;
                good = false;
                break;
            }
        }
        int back = path.back();
        for (int i : adj[back]) {
            if (!onPath[i]) {
                path.push_back(i);
                onPath[i] = true;
                good = false;
                break;
            }
        }
    }
    cout << path.size() << endl;
    while (!path.empty()) {
        int front = path.front();
        path.pop_front();
        cout << front << " ";
    }
    cout << endl;
    return 0;
}