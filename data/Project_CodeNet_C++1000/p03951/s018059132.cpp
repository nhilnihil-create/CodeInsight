#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    for (int i=0; i<n; ++i) {
        if (s.substr(i, n-i)==t.substr(0, n-i)) {
            cout << n+i;
            return 0;
        }
    }
    cout << 2*n;
    return 0;
}