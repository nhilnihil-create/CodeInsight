#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = 30000 * i;
        int x;
        cin >> x;
        p[x] = i;
    }
    for (int i = 1; i < n + 1; i++) {
        b[i] = 30000 * (n - i) + p[i];
    }
    for (int i = 0; i < n; i++) {
        cout << a[i + 1] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i + 1] << " ";
    }
}
