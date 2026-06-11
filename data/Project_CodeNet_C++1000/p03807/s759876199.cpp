#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = 1;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        if (a%2) ans = 1 - ans;
    }
    cout << (ans ? "YES" : "NO") << endl;
}