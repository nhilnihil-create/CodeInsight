#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    vector <int> t(n);
    int pi,xi;

    cin >> n;
    int sum = 0;
    for (int i=0; i < n; ++i) {
        cin >> t[i];
        sum += t[i];
    }
    cin >> m;
    for (int i=0; i < m; ++i) {
        cin >> pi >> xi;
        cout << (sum - t[pi-1] + xi) << endl;
    }

}

int main() {

    solve();
    return 0;
}
