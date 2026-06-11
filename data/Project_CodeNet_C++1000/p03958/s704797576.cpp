#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    int k, t;
    cin >> k >> t;
    int a[t];
    for (int i = 0; i < t; i++) {
        cin >> a[i];
    }

    sort(a, a + t);
    int sum = 0;
    for (int i = 0; i < t - 1; i++) {
        sum += a[i];
    }

    cout << max(0, a[t - 1] - sum - 1) << endl;;
    return 0;
}
