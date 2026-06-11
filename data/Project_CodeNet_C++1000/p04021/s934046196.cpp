#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <int> b;
    b = a;
    sort(b.begin(), b.end());
    map <int, int> c;
    for (int i = 0; i < n; i++) {
        c[b[i]] = i % 2;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 != c[a[i]]) {
            ans++;
        }
    }
    cout << ans / 2 << '\n';
    return 0;
}
