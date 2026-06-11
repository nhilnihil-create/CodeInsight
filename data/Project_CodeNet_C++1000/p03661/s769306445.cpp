#include <bits/stdc++.h>
#define INF 100000000000000
using namespace std;

int main() {
    int n;
    cin >> n;
    long b[n];
    cin >> b[0];
    for (int i = 1; i < n; i++) {
        cin >> b[i];
        b[i] += b[i - 1];
    }

    long ans = INF;
    for (int i = 0; i < n - 1; i++) {
        ans = min(abs(b[n - 1] - 2 * b[i]), ans);
    }
    cout << ans << endl;
    return 0;
}
