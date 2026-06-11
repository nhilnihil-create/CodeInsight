#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

llint n, sol;
llint a[MAXN], lef[MAXN], rig[MAXN];
vector <int> v;

void precompute () {
    v.push_back(0);
    for (int i = 1; i <= n; i++) {
        while (!v.empty() && a[v.back()] > a[i]) v.pop_back();
        lef[i] = v.back();
        v.push_back(i);
    }
    v.clear();
    v.push_back(n + 1);
    for (int i = n; i >= 1; i--) {
        while (!v.empty() && a[v.back()] > a[i]) v.pop_back();
        rig[i] = v.back();
        v.push_back(i);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    precompute();
    for (int i = 1; i <= n; i++) {
        sol += a[i] * (rig[i] - i) * (i - lef[i]);
    }
    cout << sol;
    return 0;
}
