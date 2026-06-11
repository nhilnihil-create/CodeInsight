#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    for (int i = n; i > 0; i--) {
        if (s.substr(n-i, i) == t.substr(0, i)) {
            cout << n*2-i << endl;
            return 0;
        }
    }
    cout << n*2 << endl;
}