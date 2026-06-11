#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    int ans = 1;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return;
    }
    while (ans < n) {
        ans *= 2;
    }
    cout << ((ans != n) ? (ans>>1) : ans);

}

int main() {

	solve();
    return 0;
}
