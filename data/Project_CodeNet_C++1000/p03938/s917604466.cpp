#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) a[i] = b[n-i-1] = i * n + 1;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        a[p-1] += i;
        b[p-1] += i;
    }
    for (int i = 0; i < n; i++) cout << a[i] << (i == n-1 ? '\n' : ' ');
    for (int i = 0; i < n; i++) cout << b[i] << (i == n-1 ? '\n' : ' ');
}
