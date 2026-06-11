#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    bool can = false;
    for (int i=0; i<=n; ++i) {
        for (int j=0; j<=m; ++j) {
            if (i*j + (n-i)*(m-j) == k) can = true;
        }
    }
    cout << (can ? "Yes" : "No") << endl;
}