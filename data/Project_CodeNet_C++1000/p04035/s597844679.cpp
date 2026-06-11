#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, l, pos = -1;
    cin >> n >> l;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a.at(i);
    for (int i = 1; i < n; ++i) if (a.at(i) + a.at(i + 1) >= l) {
        pos = i;
        break;
    }
    if (pos < 0) cout << "Impossible\n";
    else {
        cout << "Possible\n";
        for (int i = 1; i < pos; ++i) cout << i << '\n';
        for (int i = n - 1; i > pos; --i) cout << i << '\n';
        cout << pos << '\n';
    }
    return 0;
}
