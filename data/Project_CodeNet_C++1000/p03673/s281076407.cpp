#include <bits/stdc++.h>
using namespace std;


void solve () {
    int n;
    cin >> n;
    int p = 1;
    if (n % 2) p = 0;
    deque<int> b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i % 2 == p) {
            b.push_front(x);
        } else {
            b.push_back(x);
        }
    }
    for (auto x : b) {
        cout << x << " ";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
