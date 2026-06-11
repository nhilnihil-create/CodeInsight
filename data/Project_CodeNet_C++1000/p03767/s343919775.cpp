#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int n3 = n*3;
    vector<int> a(n3);
    for (int i = 0; i < n3; i++) cin >> a[i];
    sort (a.begin(), a.end());
    long long ans = 0;
    for (int i = n; i < n3; i += 2) ans += a[i];
    cout << ans << endl;
}