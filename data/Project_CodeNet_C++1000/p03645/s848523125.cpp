#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, m, a, b;
    cin >> n >> m;
    bitset<200000> sima1, sima2;
    rep(i,m) {
        cin >> a >> b;
        if (a == 1) 
            sima1.set(b);
        if (b == n) 
            sima2.set(a);
    }

    if ((sima1&sima2).none())
        cout << "IMPOSSIBLE" << endl;
    else
        cout << "POSSIBLE" << endl;
    return 0;
}