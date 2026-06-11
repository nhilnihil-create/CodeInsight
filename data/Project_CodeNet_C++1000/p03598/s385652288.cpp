#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, k;
    cin >> n >> k;

    int total = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int d1 = x;
        int d2 = abs(k - x);
        total += (min(d1, d2) * 2);
    }
    cout << total << endl;

    return 0;
}