#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
    }

    if (sum%2==0) cout << "YES" << endl;
    else cout << "NO" << endl;
}