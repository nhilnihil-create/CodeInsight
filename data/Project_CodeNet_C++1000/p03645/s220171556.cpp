#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> can_reach_from_1(n + 1, 0);
    vector<int> can_reach_to_n(n + 1, 0);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        if (b == n)can_reach_to_n[a] = 1;
        if (a == 1)can_reach_from_1[b] = 1;
    }

    bool ans = false;
    for (int i = 1; i <= n; i++) {
        if (can_reach_from_1[i] == 1 && can_reach_to_n[i] == 1) ans = true;
    }

    cout << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;


    return 0;
}