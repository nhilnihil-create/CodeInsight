#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> s(N);
    int sum = 0, minv = 110;
    bool ok = false;
    for (int i = 0; i < N; i++) {
        cin >> s[i];
        sum += s[i];
        if (s[i] % 10 != 0) {
            ok = true;
            minv = min(minv, s[i]);
        }
    }

    if (sum % 10 != 0) {
        cout << sum << endl;
    } else if (ok) {
        cout << sum - minv << endl;
    } else {
        cout << 0 << endl;
    }
}