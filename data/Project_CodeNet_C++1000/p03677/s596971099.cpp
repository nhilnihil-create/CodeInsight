#include <algorithm>
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    int n, m; cin >> n >> m;
    int a[2*n]; for (int i = 0; i < n; i++) { cin >> a[i]; a[i]--; }
    for (int i = 0; i < n; i++) a[i+n] = a[i];
    long long b[2*m+2] = {};
    for (int i = 1; i < n; i++) {
        int x = a[i-1], y = a[i];
        if (y < x) y += m;
        if (y == x + 1) continue;
        b[x+2]++;
        b[y+1] -= (y-x-1)+1;
        b[y+2] += y-x-1;
    }
    // for (int i = 0; i < 2*m; i++) cout << b[i] << ' '; cout << endl;
    for (int i = 1; i < 2*m; i++) b[i] += b[i-1];
    // for (int i = 0; i < 2*m; i++) cout << b[i] << ' '; cout << endl;
    for (int i = 1; i < 2*m; i++) b[i] += b[i-1];
    // for (int i = 0; i < 2*m; i++) cout << b[i] << ' '; cout << endl;
    for (int i = 0; i < m; i++) b[i] += b[i+m];
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        int x = a[i-1], y = a[i];
        if (x < y) ans += y - x;
        else ans += m + y - x;
    }
    cout << ans - *max_element(b, b+m) << endl;
}
