#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2005;

int n, k, cnt, sol;
int a[MAXN], b[MAXN];
vector <int> v[MAXN];

void dfs (int x, int rod, int dub) {
    cnt++;
    if (dub == 0) return;
    for (auto sus : v[x]) {
        if (sus == rod) continue;
        dfs(sus, x, dub - 1);
    }
}

int main () {
    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        cin >> a[i] >> b[i];
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    for (int i=1; i<=n; i++) {
        cnt = 0;
        dfs(i, 0, k/2);
        sol = max(sol, cnt);
    }
    for (int i=0; i<n-1; i++) {
        cnt = 0;
        dfs(a[i], b[i], (k-1)/2);
        dfs(b[i], a[i], (k-1)/2);
        sol = max(sol, cnt);
    }
    cout << n - sol;
    return 0;
}
