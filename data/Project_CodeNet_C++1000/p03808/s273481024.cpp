#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        sum += a.at(i);
    }

    if (sum % ((ll)n * (n + 1) / 2) != 0) {
        cout << "NO" << endl;
        return 0;
    }
    
    int k = sum / ((ll)n * (n + 1) / 2);
    
    vector<int> diff(n);
    for (int i = 0; i < n; i++) {
        diff.at(i) = a.at((i + 1) % n) - a.at(i);
    }

    for (int i = 0; i < n; i++) {
        diff.at(i) -= k;
        
        if (0 < diff.at(i) || -diff.at(i) % n != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}