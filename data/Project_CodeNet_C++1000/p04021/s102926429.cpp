#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector< int >v(n);
    vector< int >w(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        w[i] = i;
    }

    sort(w.begin(), w.end(), [&](int i, int j) {
        return v[i] < v[j];
    });

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (i&1)^(w[i]&1);
    }

    cout << ans/2 << endl;

    return 0;
}
