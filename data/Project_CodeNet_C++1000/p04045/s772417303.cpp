#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int>d(k, 0);
    for (int i = 0; i < k; i++) cin >> d[i];

    for (int i = n; i < 10e5; i++) {
        int tmp = i;
        int last = tmp % 10;
        while (tmp > 0 && find(d.begin(), d.end(), last) == d.end()) {
            tmp = tmp / 10;
            last = tmp % 10;
        }
        if (tmp == 0) {
            cout << i;
            break;
        }
    }

    return 0;
}
