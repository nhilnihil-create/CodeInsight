#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int K, T;
    cin >> K >> T;
    vector<int>a(T);
    for (int i = 0; i < T; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    if (T == 1) {
        cout << K -1 << endl;
    } else {
        int total = 0;
        for (int i = 1; i < T; i++) {
            total += a[i];
        }
        if (a[0] <= total) {
            cout << 0 << endl;
        } else {
            cout << a[0] - total - 1 << endl;
        }
    }
}
