#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;

int main() {
    int n;
    cin >> n;
    int a[n];
    int b1= 0, b2 = 0, b4 = 0;
    rep(i, n) {
        cin >> a[i];
        if (a[i] % 2 == 1) {
            b1++;
        } else if (a[i] % 4 == 0) {
            b4++;
        } else {
            b2++;
        }
    }
    if (b2 == 0) {
        if (b1 <= b4 + 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    } else {
        if (b1 <= b4) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}