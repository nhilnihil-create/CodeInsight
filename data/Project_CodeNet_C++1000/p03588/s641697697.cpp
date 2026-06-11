#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int maxr = 0;
    int minp = 1e9;
    for (int i=0; i<n; ++i) {
        int a, b; cin >> a >> b;
        maxr = max(maxr, a);
        minp = min(minp, b);
    }
    cout << maxr + minp << endl;
}