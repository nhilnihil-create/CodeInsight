#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i < n; ++i) {
        cin >> a[i];
    }
    int b[n];
    for (int i=0; 2*i+1 < n; i += 1) {
        b[i] = a[n-1-2*i];
        b[n-1-i] = a[n-1-2*i-1];
    }
    if (n&1) {
        b[n/2] = a[0];
    }
    for (int i=0; i < n; ++i) {
        cout << b[i] << " ";
    }

}

int main() {

	solve();
    return 0;
}
