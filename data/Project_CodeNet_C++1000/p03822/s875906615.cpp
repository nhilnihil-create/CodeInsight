# include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int n;
vector<int> children[100001];

int dfs(int root) {
    int size = children[root].size();
    if (size == 0) return 0;
    // mx, mn以外にも注目しなきゃいけない？
    vector<int> rets;
    for (auto &ch : children[root]) {
        int ret = dfs(ch);
        rets.push_back(ret);
    }
    int ret = -1;
    sort(rets.begin(), rets.end());
    reverse(rets.begin(), rets.end());
    for (int i = 1; i <= size; i++) {
        ret = max(ret, rets[i-1] + i);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int a; cin >> a;
        children[a].push_back(i);
    }
    cout << dfs(1) << endl;
    return 0;
}
