#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int t = k;
    for (int i=1; i < n; i++) {
        t = t * (k-1);
    }
    cout << t << "\n";
}