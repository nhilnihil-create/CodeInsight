#include <bits/stdc++.h>
using namespace std;

int main() {
    double n;
    cin >> n;
    double sum = 0;
    vector<double> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    double avg = round(sum / n);
    long long ans = 0;
    for (auto x : a) {
        long long q = avg - x;
        ans += q * q;
    }
    cout << ans;
}
