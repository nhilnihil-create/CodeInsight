#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i * j + (n - i) * (m - j) == k) {
                cout << "Yes\n";
                return 0;
            }
        }
    }

    cout << "No\n";

    return 0;
}