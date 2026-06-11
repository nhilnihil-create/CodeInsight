#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int p[n], a[n] = {}, b[n] = {};
    for (int i = 0; cin >> p[i]; i++) {
    }
    for (int i = n - 1; i >= 0; i--) {
        a[p[i] - 1] += i + 1;
        b[p[i] - 1] += i + 1;
    }
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
        b[n - i - 1] += b[n - i];
    }
    for (int i = 0; i < n; i++) {
        a[i] += i + 1;
        b[n - 1 - i] += i + 1;
    }
    for (auto i : a) {
        cout << i << ' ';
    }
    cout << '\n';
    for (auto i : b) {
        cout << i << ' ';
    }
    return 0;
}
