#include <bits/stdc++.h>

using namespace std;

int rez, n, k;
int rg[100001], a[100001];
bool viz[100001];
vector <int> v[100001];

inline void DFS(int nod) {
    viz[nod] = 1;
    rg[nod] = 1;
    for (int it : v[nod]) {
        if (!viz[it]) {
            DFS(it);
            rg[nod] = max(rg[nod], rg[it] + 1);
        }
    }
    if (rg[nod] == k && a[nod] != 1) {
        ++rez;
        rg[nod] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        v[a[i]].emplace_back(i);
    }
    if (a[1] != 1)
        ++rez;
    a[1] = 1;
    DFS(1);
    return cout << rez, 0;
}
