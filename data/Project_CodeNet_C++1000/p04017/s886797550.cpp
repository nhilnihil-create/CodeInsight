#include <bits/stdc++.h>
//#include <ext/numeric>


using namespace std;
//using namespace __gnu_cxx;

const int MAXN = 300005;
int n, l;
int arr[MAXN];
vector<int> adjList[MAXN];

void build() {
    int j = n - 1;
    for (int i = n - 1; ~i; --i) {
        while (arr[j] - arr[i] > l)
            --j;
        adjList[j].push_back(i);
    }
}

int timer;
vector<int> tin, tout;
vector<vector<int>> up;
void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];

    for (int u : adjList[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}


int ans(int u, int v) {
    int ret = 0;
    for (int i = l; i >= 0; --i) {
        if (up[u][i] < v) {
            ret += (1 << i);
            u = up[u][i];
        }
    }
    return ret + 1;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//    freopen("fence.out", "w", stdout);
#endif

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> l;
    build();
    preprocess(n - 1);
    int q;
    cin >> q;
    while(q--) {
//        cout << 1 << endl;
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        --u;
        --v;
        cout << ans(u, v) << '\n';
    }


    return 0;
}