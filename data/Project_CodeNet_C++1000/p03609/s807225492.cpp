#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, t;
    cin >> x >> t;
    int result = x - t;
    if (t >= x) {
        cout << "0";
        return 0;
    }
    cout << result;
}