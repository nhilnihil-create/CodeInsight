#include <iostream>
using namespace std;

int main() {
    long long k;
    cin >> k;
    long long a[50];
    for (int i = 0; i < k % 50; i++) {
        a[i] = k / 50 + 100 - k % 50;
    }
    for (int i = k % 50; i < 50; i++) {
        a[i] = k / 50 + 49 - k % 50;
    }
    cout << 50 << '\n';
    for (auto i : a) {
        cout << i << ' ';
    }
    return 0;
}
