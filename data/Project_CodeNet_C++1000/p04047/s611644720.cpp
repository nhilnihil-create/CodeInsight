#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(2 * n);
    int s = 0;
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < 2 * n; i += 2) {
        s += a[i];
    }
    cout << s << '\n';
    return 0;
}
