#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int M;
    cin >> M;
    int g = M;
    for (int i=1; i<n; i++) {
        int num; cin >> num;
        M = max(M, num);
        g = __gcd(g, num);
    }
    if (k % g == 0 && k <= M) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
}