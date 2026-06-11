#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, (n + 1) / 2) cout << a[n - 1 - i * 2] << " ";
    rep(i, n / 2) cout << a[n % 2 + i * 2] << " ";
    cout << "\n";
}