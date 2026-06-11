#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    int x = 0, xmax = 0;
    cin >> n;
    char c;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        if (c  == 'I') {
            ++x;
        } else {
            --x;
        }
        if (x > xmax)
            xmax = x;
    }
    cout << xmax;

}

int main() {

    solve();
    return 0;
}

