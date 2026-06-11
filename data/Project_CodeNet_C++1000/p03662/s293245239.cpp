#include <bits/stdc++.h>
#define MAX_N 100000
using namespace std;

struct Node {
    int x, c;
};

bool used[MAX_N + 1];
vector<int> es[MAX_N + 1];

void bfs(int a[], int start, int n) {
    fill(used, used + n + 1, false);
    queue<Node> que;
    que.push(Node {start, 0});
    while (!que.empty()) {
        Node p = que.front();
        que.pop();
        used[p.x] = true;
        a[p.x] = p.c;
        for (int v: es[p.x]) {
            if (!used[v])
                que.push(Node {v, p.c + 1});
        } 
    }
}

int count(int f[], int s[], int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (f[i] > s[i]) ? -1 : 1;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        es[a].push_back(b);
        es[b].push_back(a);
    }
    int f[n + 1], s[n + 1];
    bfs(f, 1, n);
    bfs(s, n, n);
    cout << ((count(f, s, n) > 0) ? "Fennec" : "Snuke") << endl;
    return 0;
}
