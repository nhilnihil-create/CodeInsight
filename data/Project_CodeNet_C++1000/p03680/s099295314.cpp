#include <iostream>
#include <algorithm>

using namespace std;

int a[100005];

void solve() {
    int n;
    cin >> n;
    int cur;
    cur = 1;
    for (int i=1; i <= n; ++i) {
        int ai;
        cin >> ai;
        a[i] = ai;
    }
    int cnt = 0;
    for (int i=1; i<= n; ++i) {
        ++cnt;
        if (a[cur] == 2) {
            cout << cnt;
            return;
        } else {
            cur = a[cur];
        }
    }
    cout << -1;

}

int main() {

	solve();
    return 0;
}
