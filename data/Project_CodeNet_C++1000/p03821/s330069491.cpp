#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    long long ans = 0;
    for (int i = n-1; i >= 0; i--) {
        a[i] += ans;
        if (a[i] % b[i] != 0) {
            int x = b[i] - (a[i] % b[i]);
            ans += x;
        }
    }
    cout << ans << endl;
}