#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main() {
    int n;
    cin >> n;
    ll a[n + 2];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = 0;
    ll ret = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] % 2) {
            if (a[i + 1]) {
                a[i]++;
                a[i + 1]--;
            }
        }
        ret += a[i] / 2;
    }
    cout << ret << endl;
    return 0;
}