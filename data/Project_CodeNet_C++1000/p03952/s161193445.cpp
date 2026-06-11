#include <bits/stdc++.h>
using namespace std;

const int N = 5 * 100 * 1000 + 10;

int n, x;
int ans[N];

void solve() {
    if (x == (2 * n) - 1 || x == 1) {
        cout << "No" << endl;
        exit(0) ;
    }
    ans[n] = x;
    ans[n - 1] = x - 1;
    ans[n + 1] = x + 1;
    int keep = 1;
    for (int i = 1; i <= 2 * n - 1; i++) {
        if (keep == x - 1)
            keep = x + 2;
        if (i < n - 1 || n + 1 < i) {
            ans[i] = keep;
            keep++;
        }
    }
    return;
}

void output() {
    cout << "Yes" << endl;
    for (int i = 1; i <= 2 * n - 1; i++)
        cout << ans[i] << "\n";
    return;
}

int main() {
    cin >> n >> x;
    solve() ;
    output() ;
    return 0;
}
