#include <bits/stdc++.h>

using namespace std;


int main() {
    int k, t;
    cin >> k >> t;
    vector<int> a(t);
    for(int i = 0; i < t; i++) {
        cin >> a[i];
    }
    int m = *max_element(a.begin(), a.end());
    cout << max(0, m - 1 - (k - m)) << "\n";
    return 0;
}