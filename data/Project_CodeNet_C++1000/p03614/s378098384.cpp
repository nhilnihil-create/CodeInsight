#include <bits/stdc++.h>
using namespace std;

int main() {
    long n, ans = 0;
    bool was = false;
    cin >> n;
    for (long i=1; i<=n; i++) {
        long p;
        cin >> p;
        if (p == i && !was) {
            ans++;
            was = true;
        } else
            was = false;
    }
    cout << ans << endl;
    return 0;
}