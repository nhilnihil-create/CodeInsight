#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void YesNo(bool x) {
    cout << (x ? "Yes" : "No") << endl;
}

int main() {
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    for (int i = 0; i < n; i++)cin >> t[i];
    sort(t.begin(), t.end());

    int ret = 1;
    int prev = 0;
    for (int i = 1; i < n; i++) {
        if (t[i] - t[prev] > k || i - prev + 1 > c) {
            ret++, prev = i;
        }
    }

    cout << ret << endl;
    return 0;
}